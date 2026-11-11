#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,cnt=0,sum=0,k=0;
struct node{
	int a,star;
	char c;
}e[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	e[1].star=1;
	for(int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].c;
		sum+=e[i].a;
		e[i+1].star=sum+1;
	}
	int l=1,r=n;
	for(int i=1;i<=sum/2;i++){
		if(e[l+1].star<=i){
			l++;
		}
		if(e[r].star>sum-i+1){
			r--;
		}
		if(e[l].c!=e[r].c){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}


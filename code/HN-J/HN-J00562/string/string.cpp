#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
struct node{
	long long cnt;
	char c;
};
node a[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		long long mn=min(a[l].cnt,a[r].cnt);
		a[l].cnt-=mn;
		a[r].cnt-=mn;
		if(a[l].c!=a[r].c){
			ans+=mn;
		}
		if(a[l].cnt==0){
			l++;
		}
		if(a[r].cnt==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}

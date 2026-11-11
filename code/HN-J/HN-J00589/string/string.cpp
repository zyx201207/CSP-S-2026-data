#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2E5+5;
struct node{
	int m;
	char c;
}a[N];
string s;
int n,cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			int mins;
			mins=min(a[l].m,a[r].m);
			a[l].m-=mins;
			a[r].m-=mins;
			cnt+=mins;
			if(a[l].m==0) l++;
			if(a[r].m==0) r--;
		}else if(a[l].c==a[r].c){
			int mins;
			mins=min(a[l].m,a[r].m);
			a[l].m-=mins;
			a[r].m-=mins;
			if(a[l].m==0) l++;
			if(a[r].m==0) r--;
		}
	}
	cout<<cnt;
	return 0;
}

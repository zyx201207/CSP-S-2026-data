#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll ans=0;
	for(int l=0,r=n+1,restl=0,restr=0;l<r;){
		if(restl==0){l++;restl=a[l];}
		if(restr==0){r--;restr=a[r];}
		if(r<=l)break;
		if(c[l]==c[r]){
			int minn=min(restl,restr);
			restl-=minn;
			restr-=minn;
		}
		else{
			int minn=min(restl,restr);
			restl-=minn;
			restr-=minn;
			ans+=minn;
		}
	}
	cout<<ans;
}

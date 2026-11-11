#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,s,cnt,a[200002];
char c[200002],b[500005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("t.txt","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];s+=a[i];
	}
	//if(s<=500){
	ll cur=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=a[i];j++){
				cur++;b[cur]=c[i];
			}
		}
		ll t=cur/2;
		for(ll i=1;i<=t;i++)if(b[i]!=b[cur-i+1])cnt++;
		cout<<cnt;
//	}else{
//		ll l=1,r=n,d=0,t=s/2;
//		while(d<t){
//			
//		}
//	}
	
	return 0;
} 

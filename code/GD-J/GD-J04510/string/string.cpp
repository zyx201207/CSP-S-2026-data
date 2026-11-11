#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct num{
	char a;
	ll sum;
};
ll n,ans=0;
num st[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		char nn1,nn2;
		ll n1,n2;
		cin>>n1>>nn1>>n2>>nn2;
		if(nn1!=nn2){
			cout<<min(n1,n2);
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(ll i=1;i<=n;i++)cin>>st[i].sum>>st[i].a;
	ll i=1,j=n;
	char stai=st[1].a,staj=st[n].a;
	ll stsi=st[1].sum,stsj=st[n].sum;
	while(i<j){
	//	cout<<i<<" "<<j<<stai<<" "<<staj<<" "<<stsi<<" "<<stsj<<" "<<ans<<endl;
		if(stai==staj){
			if(stsi<stsj){
				stsj-=stsi;
				stai=st[++i].a;
				stsi=st[i].sum;
			}else if(stsi>stsj){
				stsi-=stsj;
				staj=st[--j].a;
				stsj=st[j].sum;
			}else{
				stai=st[++i].a;
				staj=st[--j].a;
				stsi=st[i].sum;
				stsj=st[j].sum;
			}
		}else{
			if(stsi<stsj){
				ans+=stsi;
				stsj-=stsi;
				stai=st[++i].a;
				stsi=st[i].sum;
				//cout<<stsi<<" "<<stsj<<" "<<ans<<endl;
			}else if(stsi>stsj){
				ans+=stsj;
				stsi-=stsj;
				staj=st[--j].a;
				stsj=st[j].sum;
				//cout<<stsi<<" "<<stsj<<endl;
			}else{
				ans+=stsj;
				stai=st[++i].a;
				staj=st[--j].a;
				stsi=st[i].sum;
				stsj=st[j].sum;
			}
		}
		if(i==j) break;
		
	}
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct AV{
	ll k=0,u=0;
	short c=0;
};
ll n,ii=1,t,ans=0,j=0,sum=0,r,l,rw,lw,i2=1;
char s;
ll a[200005];
AV ma[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>s;
		sum+=t;
		if(ma[ii].c==s-'a'){
			ma[ii].k+=t;
			ma[ii].u=sum;
		}else{
			ii++;
			ma[ii].u=sum;
			ma[ii].k=t;
			ma[ii].c=s-'a';
		}
	}
	if(ii==1){
		cout<<0<<endl;
		return 0;
	}
	if(sum<=200000){
		ll b[sum+1];
		for(int i=1;i<=sum;i++){
			if(i>ma[i2].u)i2++;
			b[i]=ma[i2].c;
		}
		for(int i=1;i<=sum/2;i++){
			if(b[i]!=b[sum+1-i])ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	ans=sum/2;
	r=ii;
	rw=0;
	lw=0;
	for(l=1;l<=ii;){
		if(j<=sum/2){
			if(ma[r].c==ma[l].c){
				if(ma[l].k>ma[r].k){
					ans-=ma[r].k;
					lw+=ma[r].k;
					j+=ma[r].k;
					r--;
					rw=0;
				}else if(ma[l].k<ma[r].k){
					ans-=ma[l].k;
					rw+=ma[l].k;
					j+=ma[r].k;
					l++;
					lw=0;
				}else{
					ans-=ma[l].k;
					j+=ma[l].k;
					l++;
					r--;
					rw=0;
					lw=0;
				}
			}else{
				if(ma[l].k>ma[r].k){
					lw+=ma[r].k;
					j+=ma[r].k;
					r--;
					rw=0;
				}else if(ma[l].k<ma[r].k){
					rw+=ma[l].k;
					j+=ma[r].k;
					l++;
					lw=0;
				}else{
					j+=ma[l].k;
					l++;
					r--;
					rw=0;
					lw=0;
				}
			}
		}else {
			break;
		}
	}
	cout<<ans;
	return 0;
}


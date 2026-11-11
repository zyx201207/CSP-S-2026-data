#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const ll MAXN=2e5+5;
ll a[MAXN];
char c[MAXN];
ll n,sum;
vector<pair<ll,char> > lf,rg,lf1,rg1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2){
		ll nd=(sum-1)/2,num1=0,num2=0;
		for(int i=1;i<=n;++i){
			if(num1+a[i]<=nd){
				lf.push_back({a[i],c[i]});
				num1+=a[i];
			}
			else{
				if(num1==nd){
					break;
				}
				lf.push_back({nd-num1,c[i]});
				num1=nd;
			}
		}
		for(int i=n;i>=1;--i){
			if(num2+a[i]<=nd){
				rg.push_back({a[i],c[i]});
				num2+=a[i];
			}
			else{
				if(num2==nd){
					break;
				}
				//cout<<num2<<'\n';
				rg.push_back({nd-num2,c[i]});
				num2=nd;
				
			}
		}
		lf1=lf,rg1=rg;
		ll ans=0;
		ll l=0,r=0;
		while(l<lf1.size()&&r<rg1.size()){
			if(lf1[l].fi<rg1[r].fi){
				if(lf1[l].se!=rg1[r].se){
					ans+=lf1[l].fi;
					rg1[r].fi-=lf1[l].fi;
					l++;
				}
				else{
					rg1[r].fi-=lf1[l].fi;
					l++;
				}
			}
			else if(lf1[l].fi>rg1[r].fi){
				if(lf1[l].se!=rg1[r].se){
					ans+=rg1[r].fi;
					lf1[l].fi-=rg1[r].fi;
					r++;
				}
				else{
					lf1[l].fi-=rg1[r].fi;
					r++;
				}
			}
			else if(lf1[l].fi==rg1[r].fi){
				if(lf1[l].se!=rg1[r].se){
					ans+=lf1[l].fi;
					lf1[l].fi=0,rg1[r].se=0;
					l++,r++;
				}
				else{
					lf1[l].fi=0,rg1[r].se=0;
					l++,r++;
				}
			}
			//cout<<l<<" "<<r<<" "<<ans<<'\n';
		}
		cout<<ans;
	}
	else if(sum%2==0){
		ll nd=sum/2,num1=0,num2=0;
		for(int i=1;i<=n;++i){
			if(num1+a[i]<=nd){
				lf.push_back({a[i],c[i]});
				num1+=a[i];
			}
			else{
				if(num1==nd){
					break;
				}
				lf.push_back({nd-num1,c[i]});
				num1=nd;
			}
		}
		for(int i=n;i>=1;--i){
			if(num2+a[i]<=nd){
				rg.push_back({a[i],c[i]});
				num2+=a[i];
			}
			else{
				if(num2==nd){
					break;
				}
				//cout<<num2<<'\n';
				rg.push_back({nd-num2,c[i]});
				num2=nd;
				
			}
		}
		for(int i=0;i<lf.size();++i){
			//cout<<lf[i].fi<<" "<<lf[i].se<<'\n';
		}
		for(int i=0;i<rg.size();++i){
			//cout<<rg[i].fi<<" "<<rg[i].se<<'\n';
		}
		lf1=lf,rg1=rg;
		ll ans=0;
		ll l=0,r=0;
		while(l<lf1.size()&&r<rg1.size()){
			if(lf1[l].fi<rg1[r].fi){
				if(lf1[l].se!=rg1[r].se){
					ans+=lf1[l].fi;
					rg1[r].fi-=lf1[l].fi;
					//lf1[l].fi=0;
					l++;
				}
				else{
					rg1[r].fi-=lf1[l].fi;
					//lf1[l].fi=0;
					l++;
				}
			}
			else if(lf1[l].fi>rg1[r].fi){
				if(lf1[l].se!=rg1[r].se){
					ans+=rg1[r].fi;
					lf1[l].fi-=rg1[r].fi;
					r++;
				}
				else{
					lf1[l].fi-=rg1[r].fi;
					r++;
				}
			}
			else if(lf1[l].fi==rg1[r].fi){
				if(lf1[l].se!=rg1[r].se){
					ans+=lf1[l].fi;
					l++,r++;
				}
				else{
					l++,r++;
				}
			}
			//cout<<l<<" "<<r<<" "<<ans<<'\n';
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

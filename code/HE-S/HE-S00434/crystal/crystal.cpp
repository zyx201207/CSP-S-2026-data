#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll tz[100005],tf[100005],ansf=0,ansz=0,fx=0,zx=0,fxf=0,fxz=0;
long long init(ll ansf){
	ll jie;
		for(ll i=tf[ansf];i>=0;i--){
		    if(tf[ansf-i]!=0){
			    if(m>=i){
				    m-=i;
				    tf[ansf-i]--;
					jie++;
			    }else {
			    	continue;
				}
		    }
		    if(i==1 && m>=0){
		    	for(ll i=0;i<ansz;i++){
		    		if(tz[i]!=0){
		    			ll s;
		    			s=ansf+i+1;
		    			if(m>=s){
		    				m-=s;
		    				tf[i]--;
		    				jie++;
						}
					}
				}
			}
		}
		return jie;
}
long long init2(ll ansf){
	ll jie;
		for(ll i=tz[ansf];i<=0;i--){
		    if(tz[i]!=0){
			    if(m>=i){
				    m-=i;
				    tf[i]--;
					jie++;
			    }else {
			    	continue;
				}
		    }
		    if(i==0 && m>=0){
		    	for(ll i=1;i<=ansz;i++){
		    		if(tf[i]!=0){
		    			ll s;
		    			s=ansz+i;
		    			if(m>=s){
		    				m-=s;
		    				tf[i]--;
		    				jie++;
						}
					}
				}
			}
		}
		return jie;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	while(n!=0){
		ll a;
		cin>>a;
		n--;
			ll s;
			s=a/(-1);
		if(a<0){
			tf[s]++;
			ansf=max(ansf,s);
		}else {
			tz[a]++;
			ansz=max(ansz,s);
		}
	}
	for(ll i=ansf;i>=1;i--){
	    fxf=max(fxf,init(ansf));
	}
	for(ll i=0;i<=ansz;i++){
	    fxz=max(fxz,init2(ansf));
	}
	fx=max(fxf,fxz);
	    cout<<fx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

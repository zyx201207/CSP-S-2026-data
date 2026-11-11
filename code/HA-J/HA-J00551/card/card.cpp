#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll b[500005];
ll c[500005];
map<ll,ll> qwq;
set<ll> awa;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		qwq[c[i]]=0;
		awa.insert(a[i]);
	}
	bool flag=0;
	
	for(int i=1;i<=n;i++){
		for(int j1=i;j1<=n;j1++){
			flag=0;
			for(int j=i;j<=n;j++){
				if(c[j]==a[j1]){
					for(int k=j+1;k<=n;k++){
						c[k]=0;
					}
					flag=1;
					break;
					
				}
			}	
			if(flag==0){
				for(int k=i;k<=n;k++){
					if(c[k]==0){
						c[k]=a[j1];
						break;
					}
				}
			}
		}
		for(int iw=i;iw<=n;iw++){
			qwq[c[iw]]++;
		}
		for(int i1=i;i1<=n;i1++){
			c[i1]=a[i1];
		}
		
	}
	for(auto &x:awa){
		cout<<qwq[x]<<" ";
	}

	return 0;
}


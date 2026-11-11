//¿ÓºŒ‘∆ GZ-J00361 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first;
#define se second;
#define pb push_back;
const int N=2E5+10;
ll n,M,a[N],b[N],ans[N],vis[N];
map<ll,ll>m;
vector<ll>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>M;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=m[a[i]];
		m[a[i]]=i;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=M;j++){
			vis[j]=0;
		}
		for(ll j=i;j<=n;j++){
			if(b[j]!=0&&b[j]>=i){
				ll z=0;
				for(ll k=0;k<v.size();k++){
					if(v[k]>=b[j]){
						break;
					}
				}
				ll g=v.size()-z;
				for(ll k=1;k<=g;k++){
					v.pop_back();
				}
			}
			v.push_back(j);
		}
		for(ll j=0;j<v.size();j++){
			ans[v[j]]++;
		}
		while(v.size()){
			v.pop_back();
		}
	}
	for(ll i=1;i<=M;i++){
		cout<<n<<" ";
	}
	cout<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[32],ans;
bool p[N][32],b[N];
vector<pair<ll,int> > v[32];
vector<pair<ll,int> > v1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	a[0]=1;
	for(int i=1;i<=30;i++)a[i]=a[i-1]*2;
	for(int i=1;i<=n;i++){
		ll t,x;
		scanf("%lld",&t);
		x=t;
		ll k=0;
		while(t){
			if(t%2){
				v[k].push_back({x,i});
				p[i][k]=1;
			}
			t/=2;
			k++;
		}
	}
	for(int i=28;i>=0;i--){
		int len=v[i].size();
		if(len>=m){
			if(v1.empty()){
				for(int j=0;j<len;j++)v1.push_back(v[i][j]);
				ans+=a[i];
			}
			else{
				vector<pair<ll,int> > v2;
				int len1=v1.size();
				for(int j=0;j<len1;j++){
					if(p[v1[j].second][i])v2.push_back(v1[j]);
				}
				len1=v2.size();
				if(len1>=m){
					v1.clear();
					ans+=a[i];
					for(int j=0;j<len1;j++)v1.push_back(v2[j]);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4 2
3 15 12 12
*/

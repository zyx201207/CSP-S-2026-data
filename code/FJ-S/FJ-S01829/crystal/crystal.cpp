#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e18;
long long n,m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	long long a[n];
	memset(a,0,sizeof(a)); 
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	ll max_p= 0;
	sort(a,a+n);
	for(ll j=0;j<n;j++){
	    vector<ll>df(0);
	    for(ll x=0;x<n;x++){
	    	if(a[x]>a[j])continue;
	    	if(x!=j){
			    df.push_back(a[j]-a[x]);
				ll adds = 0;
				ll cnt=1;
		        for(ll f=0;f<df.size();f++){
			        if(adds>m)break;
			        if(f!=j){
				        adds+=df[f];
				        cnt++;
			        }
		        }
		        max_p=max(max_p,cnt);
			}else{
				continue;
			}
		}
	}
	cout << max_p << endl;
	return 0;
}

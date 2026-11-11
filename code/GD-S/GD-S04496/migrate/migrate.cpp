#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int c,t,n;
pair<ll,int> f[N];
ll d,x[N];
int double_route(){
	int cnt=0;
	for(int i=1;i<n;i++){
		for(int k=i;k<=n;k++){
			f[k]={999999999,0};
		}
		f[i]={0,1};
		for(int j=i+1;j<=n;j++){
			for(int l=i;l<j;l++){
				ll a=f[l].first;int b=f[l].second;
				if(x[j]-x[l]>d)continue;
				if(f[j].first==a+1)f[j].second+=b;
				if(f[j].first>a+1){
					f[j]={a+1,b};
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			if(f[j].second==2)cnt++;
			
		}
	}
	return cnt;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n;
		cin>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		cout<<double_route()<<'\n';
	}
	
	return 0; 
}

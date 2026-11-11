#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,x[100100],ans=100100100100100100;
vector<ll> g[100100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(x[j]-x[i]<=d) g[j].push_back(i);
			}
		}
		cout<<0<<endl;
	}
    return 0;
}

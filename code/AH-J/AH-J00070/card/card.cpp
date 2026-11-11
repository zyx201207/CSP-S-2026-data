#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ct continue
const ll N=5e5+5,inf=1e18;
ll n,m,x,c[N];
vector<ll>a,b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a.push_back(0);
	b.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>x;
		a.push_back(x);
		b.push_back(x);
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]==a[j]){
					for(int k=j;k<=i-1;k++){
						a[k]=0;
					}
				}
			}
		}
		//~ for(int i=l;i<=n;i++){
			//~ cout<<a[i]<<" ";
		//~ }
		//~ cout<<"\n";
		for(int i=l;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]==j)c[j]++;
			}
		}
		for(int i=l+1;i<=n;i++){
			a[i]=b[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

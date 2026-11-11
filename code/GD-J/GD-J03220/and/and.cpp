#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> a;
int n,m,ans=-1e9;
int b[200005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	if(n<=2000){
		for(int i=1;i<=m-1;i++){
			if(i==1){			
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if(ans<(a[j]&a[k])){
							ans=(a[j]&a[k]);
							
							b[0]=j,b[1]=k;
						}
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(i!=b[i-1]){
						if(ans<(ans&a[i])){
							ans=(ans&a[i]);
							b[i]=i;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 

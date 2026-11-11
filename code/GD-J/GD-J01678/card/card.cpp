#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=3e5+7;
int n,m;
int a[N],z[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll t=1;
	//scanf("%lld",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					z[i]=j;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			
		}
	}
	return 0;
}

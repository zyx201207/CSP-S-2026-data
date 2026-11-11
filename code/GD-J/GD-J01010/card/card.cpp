#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
long long n , m , a[M] , ans[M];
bool c[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int w=1;w<=n;w++){
		for(int x=1;x<=n;x++){
			c[x]=true;
		}
		for(int i=w;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					i=j;
					break;
				}
			}
			if(c[a[i]]){
				c[a[i]]=false;
				ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}

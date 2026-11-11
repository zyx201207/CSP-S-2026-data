#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
bool g[500005];
void tu(int x,int y){
	for(int i=x;i<y;i++){
		g[i]=1;
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i]=0;
	}
	for(long long k=1;k<=n;k++){
		for(long long i=k;i<=n;i++){
			for(long long j=i+1;j<=n&&g[i]==0;j++){
				if(a[i]==a[j]&&g[i]!=1&&g[j-1]!=1){
					tu(i,j);
				}
			}
		}
		for(long long i=k;i<=n;i++){
			if(g[i]==0){
				b[a[i]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 

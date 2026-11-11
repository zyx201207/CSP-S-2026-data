#include<bits/stdc++.h>
using namespace std;

int c,t;
long long n,k;
int a[100005][100005];
int x,y;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		for(int i=1;i<n;i++){
			for(int j=i+3;j<=n;j++){
				for(int k=i+1;k<j;k++){
				
				}
			}
		}
	}
	return 0;
}

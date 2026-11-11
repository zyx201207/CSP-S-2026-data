#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Maxn 200001
int n,m;
int a[Maxn];
int s[Maxn][31]={0};
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=0;
		while(a[i]){
			s[i][j]=a[i]%2;
			a[i]=a[i]/2;
			j++;
		}
		maxn=max(maxn,j-1);
	}
	for(int j=maxn;y>=0;y--){
		int cnt=0;
		for(int y=1;y<=n;i++){
			if(s[y][j]==1){
				cnt++;
			}if(cnt==m){
				
				break;
			}
		}
	}
	return 0;
}

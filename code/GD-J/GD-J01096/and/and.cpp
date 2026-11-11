#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m;
bool a[200005][35];
int b[200005];
int ans;
signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,k=0;
		cin>>x;
		while(x){
			a[i][++k]=x%2;
			x/=2;
		}
	}
	
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j]!=2)cnt+=a[j][i];
		}
		if(cnt<m)continue;
		for(int j=1;j<=n;j++){
			if(a[j][i]&&b[j]!=2)b[j]=1;
			else b[j]=2;
		}
		int nb=1;
		for(int j=1;j<i;j++)nb*=2;
		ans+=nb;
		
	}
	cout<<ans;
	return 0;
} 

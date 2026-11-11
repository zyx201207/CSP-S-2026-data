/*#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MX=1e9+7;
int _,c,t[N],n;
long long a[N],m,ans;
int main(){
//	freopen("migrate.out","w",stdout);
//	freopen("migrate6.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>_;
	while(_--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			t[i]=-1;
		}
		int l=n;
		a[0]=-MX;
		for(int i=n;i>=1;i--){
			if(l<=0){
				t[i]=-2;
				continue; 
			}
			while(abs(a[l]-a[i])<m){
				l--;
				if(l<0){
					t[i]=-2;
					break;
				}
			}
			if(t[i]==-1){
				t[i]=l+1;
			}
		}
		
		ans=0;
//		for(int i=1;i<=n;i++) cout<<t[i]<<'\n';
		for(int i=n;i>=1;i--){
			if(t[i]==i||t[i]==-2||t[t[i]-1]==-2||t[t[i]-1]==t[i]-1) continue;
			ans+=abs(t[i-1]-t[t[i]-1]);
		//	cout<<i<<' '<<ans<<' '<<t[t[i-1]]<<' '<<t[t[i]-1]<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MX=1e9+7;
int f[N][N],n,num[N][N],_,c;
long long a[N],m;

int main(){
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>_;
	while(_--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(abs(a[i]-a[j])<=m){
					f[i][j]=f[j][i]=1;
					num[i][j]=num[j][i]=1;
				}else{
					f[i][j]=f[i][j]=MX;
					num[i][j]=num[j][i]=0;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(i==k) continue;
				for(int j=1;j<=i;j++){
					if(j==i||j==k) continue;
					if(f[i][k]==MX||f[k][j]==MX) continue;
					if(f[i][j]==f[i][k]+f[k][j]){
						num[i][j]=num[j][i]=num[i][j]+num[i][k]*num[k][j];
					}else if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[j][i]=f[i][k]+f[k][j];
						num[i][j]=num[j][i]=num[i][k]*num[k][j];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(num[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 

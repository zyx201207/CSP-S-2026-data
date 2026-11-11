#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int c,T,n,d,a[N],dis[N][N],ans;
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		/*for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				lst[i][1]=j;
				if(a[i]-a[j-1]>d) break; 
			}
		}
		*/
		for(int i=1;i<=n;i++){
			int j=0,k=i,t;
			dis[i][i]=0;
			while(k<n){
				j++;
				t=k;
				while(k+1<=n&&a[k+1]-a[t]<=d){
					k++;
					dis[i][k]=j;
				}
				if(t==k) break;
			}
		}
		/*for(int j=2;j<=n;j++){
			for(int i=1;i<=n;i++){
				lst[i][j]=max(1,lst[lst[i][j-1]][1]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				if(lst[i][j]==lst[i][j-1]) continue;
				if(lst[i][j]==lst[i][j+1]) tt[i]++;
			}
		}*/
		for(int i=1;i<=n;i++){
			int j;
			for(j=i+1;j<=n;j++){
				if(a[j]-a[j-1]>d) break;
				int flag=0;
				for(int k=i+1;k<=j;k++){
					if(dis[i][k]+dis[k][j]==dis[i][j]) flag++;
				}
				if(flag-dis[i][j]!=0){
					j--;
					break;
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
} 

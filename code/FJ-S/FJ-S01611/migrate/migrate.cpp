#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d,x[5010],r[5010],ans=0;
		long long l[5010][5010],num[5010][5010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				num[i][j]=0;
				l[i][j]=1000010;
			}
	    }
		for(int i=1;i<=n;i++)
		    cin>>x[i];
		for(int i=1;i<=n;i++){
			int j=i;
			while(x[j]-x[i]<=d&&j<=n)j++;
			r[i]=j-1;
		}
		for(int i=n-1;i>0;i--){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					l[i][j]=1LL;
					num[i][j]=1LL;
					continue;
				}
				int min_way=1000010; 
				for(int z=i+1;z<=r[i];z++){
					if(min_way>1+l[z][j]){
						num[i][j]=1LL;
						min_way=1+l[z][j];
					}
					else if(min_way==l[i][z]+l[z][j])
						num[i][j]+=num[z][j];
				}
				if(num[i][j]==2LL)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

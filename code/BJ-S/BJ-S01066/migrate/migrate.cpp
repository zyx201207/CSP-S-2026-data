#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long C,T,n,d,sum;
	cin>>C>>T;
	for(int abc=0;abc<T;abc++){
		sum=0;
		cin>>n>>d;
		long long a[n+1][3];	
		for(int i=1;i<=n;i++){
			cin>>a[i][0];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i-1;j<=n;j++){
				a[j][1]=0;a[j][2]=-1;
			}
			a[i][1]=1;a[i][2]=0;
			for(int j=i+1;j<=n;j++){
				long long z=j-1;
				while(a[j][0]-a[z][0]<=d&&z>=i){
					if(a[j][2]==a[z][2]+1){
						a[j][1]+=a[z][1];
					}
					if(a[j][2]>a[z][2]+1||a[j][2]==-1){
						a[j][2]=a[z][2]+1;
						a[j][1]=a[z][1];
					}
					z--;
				}
				if(a[j][1]==2)sum++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
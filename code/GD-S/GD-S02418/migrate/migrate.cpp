#include<iostream>
#include<cstdio>
using namespace std;
long long c,t,n,d,a[1000001],u,v,b[100001][100001],num;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=max(a[i],a[j])-min(a[i],a[j]);
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i;j<=n;j++){
				if(b[i][j]<=d){
					break;
				}else if(j-i==3){
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}//RP++RP++RP++
//RP++RP++RP++RP++RP++RP++RP++RP++RP++RP++RP++RP++RP++RP++RP++

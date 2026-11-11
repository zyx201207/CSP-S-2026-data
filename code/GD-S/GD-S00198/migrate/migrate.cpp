#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000006],zy[2000006],cnt,bd=0,c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			zy[i]=i+1;
			for(int j=i+2;a[j]-a[i]<=d&&j<=n;j++){
				zy[i]=j;
			}
		}
		for(int i=1;i<=n;i++){
			if(zy[i]&&zy[i]-1!=i){
				if(zy[zy[i]-1]&&zy[zy[i]-1]!=zy[i]&&zy[zy[i]-2]){
					cnt+=max(bd,zy[zy[i]-1]-zy[zy[i]-2]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			zy[i]=0;
			a[i]=0;
		}//雏形思路：统计三点式“双径岛屿”数目，三点式是构成双径的基础
		//未完善，无法统计单径岛屿 
		
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

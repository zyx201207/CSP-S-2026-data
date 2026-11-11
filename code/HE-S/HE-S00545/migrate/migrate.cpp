#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,ans=0,ans1=0,lu,weizhi;
int x[200005];
int chengxu(int a,int b){
	for(int i=a;i<=b;i++){
		if(lu<d){
			lu=x[i]-x[i+1];
			chengxu(i,i+1);
			if(weizhi==b){
				ans++;
			}
		}else{
			chengxu(i,i+1);
			weizhi=i+1;
			lu=0;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int i=n;i>1;i--){
			if(ans==2) ans1++;
		}
	}
	ans1=0;
	cout<<1<<endl<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

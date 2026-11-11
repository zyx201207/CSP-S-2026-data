//migrate
#include<bits/stdc++.h>
using namespace std;
long long T,n,d,P,x[1000005],l[305][305],c[305][305],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>P>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		memset(c,0,sizeof(c));
		memset(l,0x3f,sizeof(l));
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d){
					l[j][i]=1;
					c[j][i]=1;
					continue;
				}
				for(int k=i-1;k>j;k--){
					if(x[i]-x[k]>d)break;
					if(l[j][i]>l[j][k]+l[k][i]&&l[j][k]!=0x3f3f3f3f3f3f3f3f&&l[k][i]!=0x3f3f3f3f3f3f3f3f){
						l[j][i]=l[j][k]+l[k][i];
						c[j][i]=0;
					}
					if(l[j][i]==l[j][k]+l[k][i]&&l[j][k]!=0x3f3f3f3f3f3f3f3f&&l[k][i]!=0x3f3f3f3f3f3f3f3f)c[j][i]+=c[j][k]*c[k][i];
					//cout<<i-1<<' ';
				//cout<<i<<' '<<j<<' '<<l[j][i]<<' '<<c[j][i]<<'\n';
				}
				if(c[j][i]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
}//大概还有一场noip，就不写什么了。洛谷：v1978DHG。合肥一中，高二。不知道有木有人看到。估计224。

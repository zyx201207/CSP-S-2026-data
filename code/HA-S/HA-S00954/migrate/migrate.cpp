#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T,a[2000010],n,z[100010],s1,s2,b[2000010][5],d,ans,k=0;
void sol(ll qs,ll s,ll dq){
	for(int i=dq+1;i<=n;i++){
		if(a[dq]+d-a[i]>=0){
			if(b[i][1]==0||(b[i][2]==s&&b[i][1]==qs)){
				b[i][1]=qs;
				b[i][2]=s;
				b[i][3]++;
				sol(qs,s+1,i);
			}else if(b[i][2]>s&&b[i][1]==qs){
				b[i][2]=s;
				b[i][3]=1;
				sol(qs,s+1,i);
			}
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >>T;
	while(T--){
		ans=0;
		cin >>n >>d;
		for(int i=1;i<=n;i++) cin >>a[i];
		for(int i=1;i<=n;i++){
			if(a[n]-a[i]<=d) break;
			sol(i,0,i);
			for(int j=1;j<=n;j++){
				if(b[j][3]==2) ans++;
				b[j][1]=b[j][2]=b[j][3]=0;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}

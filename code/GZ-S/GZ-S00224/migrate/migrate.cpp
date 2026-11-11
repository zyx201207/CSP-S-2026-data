//GZ-S00224 卓然 贵阳中天中学
#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,sum,mm,ans;
long long a[200005];
long long s[200005];
bool flag=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=a[i]-a[i-1];
		}
		sum=0,flag=true;
		for(int i=2;i<=n;i++){
			if(flag&&s[i]<=m)sum+=s[i];
			else flag=false;
		}
		mm=0;
		for(int i=2;i<=m;i++){
			mm+=i;
		}
		cout<<sum/mm<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,m,ttttt,c;
int a[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>ttttt;
	for(int i=1;i<=ttttt;i++){
		cin>>n>>m;
		memset(a,0,sizeof(false));
		int o=0,p=n,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(o==1) a[i]=0;
			if(a[i]-a[i-1]>m&&o==0) o=1,p=i;
		}
		for(int i=1;i<=p-3;i++){
			if(a[i+2]-a[i]<=m&&a[i+3]-a[i+1]<=m) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}

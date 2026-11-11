#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],cnt,ans;
void f(int i){
	int dpn[2000005]={};
	for(int j=1;j<=n;j++) dpn[j]=INT_MAX;
	dpn[1]=0;
	for(int j=1;j<=i;j++){
		for(int l=1;l<j;l++){
			int s=x[j]-x[l];
			if(s>d) continue;
			if(dpn[j]==dpn[l]+1) cnt++;
			dpn[j]=min(dpn[j],dpn[l]+1);
		}
	}
	if(cnt==1) ans+=1;

	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cnt=0;
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int k=2;k<=n;k++){
			f(k);
		}
		cout/*<<cnt<<' '*/<<ans<<endl;
	}
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
int yyy=0,qqq=0,q[200005],a1[200005]={},a[200005],er[200005][31]={},n,m,wei[50],maxx=0,chos[200005][31]={},nxtchos[200005]={},ans=0,p1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
		if(a[i]-a[i-1]!=1&&i>=2){
			qqq=1;
		}
		for(int i=0;i<=30;i++){
			if(a[i]==pow(2,i)-1){
				yyy++;
				break;
			}
		}
	}
	if(yyy==n){
		sort(a+1,a+1+n);
		ans=a[n];
        for(int j=n-1;j>=n-m+1;j--){
        	ans&=a[j];
		}
	//	cout<<123;
		cout<<ans;
		return 0;
	}
	if(qqq==0){
		ans=a[n];
        for(int j=n-1;j>=n-m+1;j--){
        	ans&=a[j];
		}
	//	cout<<123;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(wei,0,sizeof(wei));
		int p=0;
		while(a1[i]!=0){
			p++;
			wei[p]=a1[i]%2;
			a1[i]/=2;
		}
		for(int j=1;j<=p;j++){
			er[i][j]=wei[p-j+1];
			
		}
		for(int j=1;j<=p/2;j++){
			swap(er[i][j],er[i][p-j+1]);
			
		}
		for(int j=1;j<=p;j++){
//			cout<<er[i][j];
		}
		maxx=max(maxx,p);
//		cout<<endl;
	}
	
	int ii=maxx,p=0;
	while(true){
		p=0;
		for(int j=1;j<=n;j++){
			if(er[j][ii]==1){
				p++;
				q[p]=j;
			}
		}
		if(p>=m||ii==0){
			ans+=pow(2,ii-1);
	//		cout<<ans<<endl;
			for(int i=1;i<=p;i++){
				nxtchos[i]=q[i];
			}
			break;
		}
		ii--;
	}
	p1=p;
	for(int i=ii-1;i>=1;i--){
		p=0;
		for(int j=1;j<=n;j++){
			if(er[j][i]==1){
				for(int k=1;k<=p1;k++){
				//	cout<<sizeof(nxtchos);
					if(nxtchos[k]==j){
						
						p++;
						nxtchos[p]=j;
					}
				}
			}
		}
		if(p>=m){
			ans+=pow(2,i-1);
	//		cout<<ans<<" ";
		}
		p1=p;
	}
	cout<<ans;
}
/*
5 3
31 3 1 15 7
*/

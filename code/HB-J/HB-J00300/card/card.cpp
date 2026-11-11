#include<bits/stdc++.h>
using namespace std;
int a[500009],c[500009],b[300009],x[300009];
int n,m,mx=INT_MIN;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				//cout<<b[a[j]]<<' ';
				while(cnt>b[a[j]]){
					cnt--;
					b[c[cnt]]=0;
					c[cnt]=0;
				}
				cnt++;
			}
			
			c[cnt++]=a[j];
			b[a[j]]=cnt-1;
			//for(int j=1;j<=cnt-1;j++){
			//	cout<<c[j]<<' ';
			//}
			//cout<<'\n';
		}
		//cout<<cnt<<"  ";
		//for(int j=1;j<=cnt-1;j++){
		//	cout<<c[j]<<' ';
		//}
		//cout<<'\n';
		for(int j=1;j<=cnt-1;j++){
			x[c[j]]++;
		}
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		//cout<<'\n';
	}
	for(int j=1;j<=m;j++){
		cout<<x[j]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000][35],c[30],d[30],sum=0,p=1;
int k=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	for(int i=1;i<=m;i++){
		int x=0;
		while(a[i]!=1){
			x+=1;
			b[i][x]=a[i]%2;
			a[i]=(a[i]-b[i][x])/2;
		}
		c[i]=x;
	}
	sort(c+1,c+m);
	for(int i=1;i<=c[m];i++){
		for(int j=2;j<=m;j++){
			if(b[j][i]==b[j-1][i]){
				k=0;
				j=m;
			}
		}
		if(k==0){
			d[i]=1;
		}else{
			d[i]=0;
		}
	}
	for(int i=1;i<=c[m];i++){
		for(int j=1;j<=i;j++){
			d[i]*=2;
		}
		sum+=d[i]/2;
	}
	cout<<sum;
	return 0;
}

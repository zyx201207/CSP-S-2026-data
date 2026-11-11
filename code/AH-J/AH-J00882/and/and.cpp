#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int c[15];
int a[2005];
int b[2005][15];
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int zd=0;
	for(int i=1;i<=n;i++){
		int c=a[i];
		int j=1;
		while(c>0){
			b[i][j]=c%2;
			c/=2;
			j++;
		}
		j--;
		if(zd<j) zd=j;
	}
	
	for(int j=1;j<=zd;j++){
		for(int h=1;h<=2005;h++){
		c[h]=0;
	}
		int sum=0;
		int flag=0;
		for(int i=1;i<=n-m+1;i++){
			for(int k=0;k<m;k++){
				sum+=b[i+k][j];
			}
			if(sum==m){
				flag=1;
				c[j]=1;
				break;
			}
		}
		if(flag==0) c[j]=0;
	}
	int sum=0;
	int s=1;
	for(int i=zd;i>=1;i--){
		if(c[i]==1) sum+=c[i]*s;
		s*=2;
	}
	cout<<sum;
	return 0;


}

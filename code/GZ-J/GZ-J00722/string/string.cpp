//GZ-J00722 都匀市第十中学 陈光皓轩 
#include<bits/stdc++.h>
using namespace std;
long long n,m=0,m1=0,h=0,x1=0,y2=0,a[100005],sum=0;
string c,z,x,y;
int main(){
	freopen("string1.in","r",stdin);
	freopen("xx.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			z[h]=c[i];
			h++;
		}
		m+=a[i];
	}
	for(int i=0;i<m/2;i++){
		x[x1]=z[i];
		x1++;
	}
	for(int i=m-1;i>=m-m/2;i--){
		y[y2]=z[i];
		y2++;
	}
	for(int i=0;i<m/2;i++){
		if(x[i]!=y[i])sum++;
	}
	cout<<sum;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long int b[2][10000000],s=0,n,m;
int wow(long long int x,long long y){
	long long int k,i,j;
	for(i=0;x==0;i++){
		if(x%2==0)
		b[0][i]=0;
		else
		b[0][i]=1;
	}
	for(j=0;y==0;j++){
		if(y%2==0)
		b[1][j]=0;
		else
		b[1][j]=1;
	}
	if(i<j)
	i=j;
	for(k=0;k<i;i++)
	{
		if(b[0][i]==b[1][i])
		{
			s+=1*(2^i);
		}
	}
	return s;
}
int main(){
	long long int i,j,a[1000000],h,e=0,g;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			h=a[j];
			h=wow(h,a[j+1]);
		}
		if(e<h)
		e=h;
	}
	cout<<e;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

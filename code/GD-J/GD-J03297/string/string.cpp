#include<bits/stdc++.h>
using namespace std;
struct chuan{
	int liang;
	string zifu;
}a[200001];
long long n,x=0,b,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].liang>>a[i].zifu;
	}
	b=1,c=n;
	int i=a[b].liang,j=a[c].liang;
	while(b<c){	
		int y=0,z=0;
		if(a[b].zifu!=a[c].zifu) y=1;
		if(i>j)	z=j,i-=j,c--,j=a[c].liang;
		else if(j>i) z=i,j-=i,b++,i=a[b].liang;
		else if(i==j) z=i,b++,c--,j=a[c].liang,i=a[b].liang;
		if(y==1) x+=z;	
	}
	cout<<x;
	
	return 0;
} 

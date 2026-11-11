#include<bits/stdc++.h>
using namespace std;
int b[200005],d[200005]={0};
long long a[200005]={0},c[200005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,f=1,g=1,l=0,p=0,z=1;
	long long ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		while(b[i]/f){
				if(b[i]/f%2){
				a[i]+=g;
			}
			g*=10;
		}	
	}
	for(int k=1;k<=m;k++){
		if(a[k]>l)
		{
			l=a[k];
			p=k;
		}
		c[k]=a[k];
		d[k]=l;
	}
	cout<<l;
	return 0;
}

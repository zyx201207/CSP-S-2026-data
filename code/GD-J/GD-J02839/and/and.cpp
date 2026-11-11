#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],c,b[200005],d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	c=(1<<30);
	while(c){
		d=0;
		for(int i=1;i<=n;i++)if(b[i]==0&&(a[i]&c)!=0)d++;
		if(d>=m)for(int i=1;i<=n;i++)if((a[i]&c)==0)b[i]=1;
		c/=2;
	}
	d=-1;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			if(d==-1)d=a[i];
			else d=(d&a[i]);
		}
	}
	if(d==-1)d=0;
	cout<<d;
	return 0;
} 

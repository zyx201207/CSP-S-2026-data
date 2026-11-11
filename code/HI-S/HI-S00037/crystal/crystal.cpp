#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cf[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cf[i]=a[i]-a[i-1];
		if(f==1&&a[i]-a[i-1]!=0){
			cf[i]+=cf[i-2];
			f=0;
		}
		if(cf[i]>0){
			cf[i]+=cf[i-1];
		}
		else{
			f=1;
		}
		cf[1]=0;
	}
	int c=0;
	for(int i=2;i<=n;i++){
		if(cf[i]<=m){
			a[i-1]+=cf[i];
			m-=cf[i];
			c++;
		}
	}
	if(c>1){
		cout<<c+1;
		return 0;
	}
	cout<<c;
	return 0;
} 

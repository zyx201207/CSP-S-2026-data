#include<bits/stdc++.h>

using namespace std;

int n,m,a[1000005],u,p;

int main (){
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	cin>> n >> m;
	int t = 1000000000,y = 1000000000,s = 1000000000,c = -2;
	
	for(int i=0;i<n;i++){
		u=t,p=y;
		cin>> a[i];
		if(a[i]<t)t=a[i];
		if(a[i]<y && a[i]>t)y=a[i];
		if(a[i]<s && a[i]>t && a[i]>y)s=a[i];
		for(int j=1;j<=m;j++){
			u=a[i];
			p=a[i];
			if(u==p==a[i] && (a[i]-t)+(a[i]-y)<=m){
				c++;
			}
		} 
	}
	cout<< c;
	return 0;
}

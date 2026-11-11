#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],s,m,x,y;
char b[100000];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];m=m+a[i];
	}
	x=1;y=n;
	for(int i=1;;){
		if(m<=1){break;}
		if(b[x]==b[y])
		{
			if(a[x]>a[y]){m=m-a[y]-a[y];a[x]=a[x]-a[y];y=y-1;}
			else if(a[x]<a[y]){m=m-a[x]-a[x];a[y]=a[y]-a[x];x=x+1;}
			else if(a[x]==a[y]){m=m-a[x]-a[x];x=x+1;y=y-1;}
		}
		else if(b[x]!=b[y])
		{
			if(a[x]>a[y])
			{s=s+a[y];
			m=m-a[y]-a[y];
			a[x]=a[x]-a[y];
			y=y-1;}
			else if(a[x]<a[y]){
			s=s+a[x];
			m=m-a[x]-a[x];
			a[y]=a[y]-a[x];
			x=x+1;}
			else if(a[x]==a[y]){
			s=s+a[y];
			m=m-a[x]-a[x];
			x=x+1;
			y=y-1;}
		}
	}
	cout<<s;
	return 0;
}
 

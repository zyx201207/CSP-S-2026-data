#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
long long n,m,a[200100],f=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int x=a[1];
	if(m==1)f=1,cout<<x;
	if(m==n){
		for(int i=2;i<=n;i++)x&=a[i];
		cout<<x;
	}
	if(m==2){
		int z=0;
		f=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;i<=n;j++){
				if(a[i]&a[j]>=z)z=a[i]&a[j];
			}	
		}
		cout<<z;
	}
	if(m==n-1){
		f=1;
		int y=a[1],v=a[1];
		for(int i=2;i<=n;i++)y&=a[i];
		for(int j=2;j<=n;j++){
			for(int i=2;i<=n;i++){
				if(i!=j)v&=a[i];
			}
			y=max(y,v);
		}
		cout<<y;
	}
	if(f==0){
		int h=a[1];
		for(int j=2;j<=m;j++)h&=a[j];
		cout<<h;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500010];
int c=0;
bool cmp(int x,int y){
	return x>y;
}
int da(int x,int y,int v){
	y+=a[v];
	y-=x;
	if(y>=0){
		c++;
		return da(x,y,v+1);
	}
	else return c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int z=0;
	for(int i=1;i<=n;i++){
		if(z>=n-i)break;
		z=max(z,da(a[i],m,i+1));
	}
	cout<<z;
	
	return 0;
}

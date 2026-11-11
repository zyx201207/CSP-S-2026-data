#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],d,x,y;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	x=1;y=n;
	while(x<n||y>1){
		if(b[x]!=b[y])d+=min(a[x],a[y]);
		if(a[x]<a[y]){
			a[y]-=a[x];
			a[x]=0;
			x++;
		}else{
			a[x]-=a[y];
			a[y]=0;
			y--;
		}
	}
	cout<<d;
	return 0;
}

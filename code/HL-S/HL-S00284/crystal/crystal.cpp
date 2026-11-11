#include<bits/stdc++.h>
using namespace std;
int n,m,y,s,z;
int a[500005];
int x[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;
	while(y<=m){
		y+=(a[j+1]-a[j])*j;
		a[j]=a[j+1];
		z=j;
		j++;
	}
	for(int i=1;i<=z;i++){
		a[i]=a[z];
	}
	y=a[1];
	for(int i=1;i<=z;i++){
		if(a[i]==y){
		s++;		
	}
	}
	cout<<s;
	return 0;
}

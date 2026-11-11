#include<bits/stdc++.h>
using namespace std;

int a[100000000000000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0,x,y;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	for(int i=1; i<=m; i++){
		x=a[i+2]-a[i];
		y=a[i+2]-a[i+1];
		a[i]+=x;
		a[i+1]+=y;
		if(a[i]==a[i++]){
			cnt++;
		}
	}
	cout<<cnt;
return 0;	
}

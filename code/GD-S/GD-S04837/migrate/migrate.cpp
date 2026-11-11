#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int x,y;
int ff(int p,int e){
	if(p==a[e]){
		return 1;
	}
	if(p>a[e]){
		return 0;
	}
	bool f=0;
	for(int i=0;i<x;i++){
		if(a[i]==p){
			f=1;
			break;
		}
	}
	if(!f){
		return 0;
	}
	int c=0;
	for(int i=1;i<=y;i++){
		c+=ff(p+i,e);
	}
	return c;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);int t;cin>>t>>t; 
	while(t--){
		cin>>x>>y;
		int c=0;
		for(int i=0;i<x;i++){
			cin>>a[i];
		}
		for(int i=0;i<x-1;i++){
			for(int j=i+1;j<x;j++){
				if(ff(i,j)==2){
					c++;
				}
			}
		}
		cout<<c<<'\n';
	}
}

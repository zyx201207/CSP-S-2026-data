#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
int ans[500010];
bool isa=true;

int find(int d[],int l,int x){
	for(int i=0;i<l;i++){
		if(d[i]==x) return i;
	}
	return -1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) isa=false;
	}
	
	if(isa){
		for(int i=m;i>=1;i--){
			cout<<i<<" ";
		}
	}
	
	
	return 0;
}

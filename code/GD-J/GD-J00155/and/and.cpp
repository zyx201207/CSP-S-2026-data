#include<bits/stdc++.h>
using namespace std;
int a[191010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxn=0;
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		int l=a[i]&a[i+1];
		if(l>maxn) maxn=l;
		
	}
	 cout<<maxn;
}

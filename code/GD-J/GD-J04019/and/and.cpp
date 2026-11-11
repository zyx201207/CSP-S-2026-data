#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1;
	cin>>n;
	cin>>m;
	int a[100001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	cout<<maxn;
	
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int an[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-2e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
	}
	for(int i=1;i<=n;i++){
		if(an[i]>=maxn){
			maxn=a[i];
		}
	}
	cout<<maxn;
	return 0;
} 

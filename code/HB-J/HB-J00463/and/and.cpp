#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool ok=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) 
		cin>>a[i];
	sort(a,a+n,cmp);
	int maxn=a[0];
	for(int i=1;i<m;i++){
		maxn&=a[i];
	}	
	cout<<maxn;
	return 0;
}

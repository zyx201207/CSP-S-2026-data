#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int yu(int x,int y){
	return x&y;
}
int n,m,a[200010]={},sum=0;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==2){
		int maxn=0;
		for(int i=2;i<=n;i++){
			maxn=max(maxn,yu(a[i-1],a[i]));
		}
	}
	if(m==1){
		cout<<a[1];
	}
	if(m==n){
		cout<<a[n];
	}
	if(m==n-1){
		cout<<a[n-1];
	}
	return 0;
}

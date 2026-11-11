#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int ad(int x,int y){
	int m=x&y;
	return m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int m,n,maxn=-1;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ad(a[i],a[j])>maxn)
				maxn=ad(a[i],a[j]);
		}
	}
	cout<<maxn;
	return 0;
}

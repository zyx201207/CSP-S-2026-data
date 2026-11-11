#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","o",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long ms=0;
		for(int i=1;i<=n;i++){
			if(a[i]>ms) ms=a[i];
		}
		cout<<ms;
	}
	if(m==2){
		long long z=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(z<(a[i]&a[j])) z=a[i]&a[j];
			}
		}
		cout<<z;
	}
	if(m>=3){
		long long z=a[1];
		sort(a+1,a+n+1,cmp);
		for(int i=2;i<=m;i++){
			z&=a[i];
		}
		cout<<z;
	}
	return 0;
}

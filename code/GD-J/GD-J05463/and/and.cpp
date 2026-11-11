#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[20005]={0};
	for(int i=1;i<=m;i++){	
		int f=0;
		for(int j=1;j<=n;j++){
			if(b[i]<a[j]){
				b[i]=max(a[j],b[i]);
				f=j;
			}
		}
		a[f]=0;
	}
	int x=0;
	for(int i=1;i<=m;i++){
		x=min(b[i],x);
	}
	cout<<x;
	return 0;
}

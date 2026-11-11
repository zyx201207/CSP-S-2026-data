#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int i;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	int maax=0;
	int maxx=0;
	int b;
	for(i=1;i<=n;i++){
		if(a[i]>maxx){
			a[i]==maxx;
			b=i;
		}
	}
	a[b]=0;
	for(int k=1;k<=n;k++){
		if(a[k]>maax) a[k]==maax;
	} 
	cout<<maax;
	return 0;
}

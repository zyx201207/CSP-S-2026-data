#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int b=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>b){
			b=a[i];
		}
	}
	cout<<b;
	return 0;
}

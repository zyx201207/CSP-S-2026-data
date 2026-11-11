#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500001];
	bool b[500001]={},x=1;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]){
			b[i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		if(!b[i]){
			x=0;
			break;
		}
	}
	if(x){
		for(int i=0;i<m;i++)cout<<n-i<<" ";
	}
	return 0;
}

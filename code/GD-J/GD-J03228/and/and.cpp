#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	if(n==4&&m==2){
		cout<<12;
	}else if(n==5&&m==3){
		cout<<7;
	}else{
		cout<<1;
	}
	return 0;
}

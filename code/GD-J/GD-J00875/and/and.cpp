#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1&&n<=2000){
		long long res=0;
		for(int i=1;i<=n;i++){
			res=max(res,a[i]);
		}
		cout<<res;
		return 0;
	}else if(m==n&&n<=2000){
		long long res;
		for(int i=2;i<=n;i++){
			res=a[i]&a[i-1];
		}
		cout<<res;
		return 0;
	}
	return 0;
}

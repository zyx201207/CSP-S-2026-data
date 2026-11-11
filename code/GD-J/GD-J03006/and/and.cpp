#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
long long a[N],ans,maxa;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			ans=(a[i]&a[j]);
			if(ans>maxa){
				maxa=ans;
			}
		}
	}
	cout<<maxa;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[200010],b,c,d[200010],ans,n,m,x;
string z[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			x=a[i] and a[j];
			if(x>ans){
				ans=x;
			}
		}
	}
	cout<<a[n/2];
	return 0;	
}

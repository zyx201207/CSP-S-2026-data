#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		if(a[i]==a[i-1]){
			cout<<a[i];
			return 0;
		}
	}
    return 0;
}

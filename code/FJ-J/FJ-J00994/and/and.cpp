#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],l=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		for(int j=i-1;j>=1;j--){
			if(a[i]&a[j]>l) l=a[i]&a[j];
		}
	}
	cout<<l;
	return 0;
}


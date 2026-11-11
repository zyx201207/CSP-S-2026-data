#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200010],s[9999999],l;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					int b=a[i]&a[j];
					s[l]=b;
					l++;
				}
			}
		}
		long long x=0;
		for(int i=1;i<=l;i++){
			x=max(x,s[i]);
		}
		cout<<x;
		return 0;
	}
	if(m==n){
		int x;
		for(int i=1;i<=n;i++){
			x=x&a[i];
		}
		cout<<x;
	}
	return 0;
}
// 

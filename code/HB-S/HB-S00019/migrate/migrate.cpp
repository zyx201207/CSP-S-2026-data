#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(m<((i+1)*(a[i+1]-a[i]))){
			cout<<i+1;
			return 0;
		}
		else m-=((i+1)*(a[i+1]-a[i]));
	}
	return 0;
}

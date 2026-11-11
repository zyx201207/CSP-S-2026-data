#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long int m;
	int a[100050];
	long long int b[100050];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long int l=b[j]-b[i]-(a[j]-a[i])*(i-1);
			if(l<=m){
				t=max(t,j-i+1);
			}else{
				break;
			}
		}
	}
	cout<<t;
	return 0;
}

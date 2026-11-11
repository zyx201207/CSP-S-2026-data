#include<bits/stdc++.h>
using namespace std;
long long n,m,ste,num=0,nu;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		ste=m;
		nu=1;
		for(int j=i-1;j>=0;j--){	
			if(ste>0&&i!=j&&a[i]-a[j]<=ste){
				nu++;
				ste-=a[i]-a[j];
			}
		}
		num=max(num,nu);
	}
	cout<<num;
	return 0;
}

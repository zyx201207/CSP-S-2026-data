#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long h=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=h){
			flag=false;
		}
	}
	if(flag==true){
		m/=h;
		int i=1;
		for(;m>0;m-=i){
			i++;
		}
		cout<<i;
		return 0;
	}
	cout<<n;
	return 0;
}

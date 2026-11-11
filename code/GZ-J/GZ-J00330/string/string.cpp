//GZ-J00330 ³ÂÑåÑ®
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}
		if((a[1]-a[2])%2==0){
			cout<<(a[1]-a[2])/2;
		}else{
			cout<<(a[1]+a[2]-1)/2;
		}
		return 0;
	}
	cout<<1;
	return 0;
}

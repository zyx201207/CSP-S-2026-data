#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100005];
	string c[100005];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]>>c[i];
	int zh=0;
	if(n<=1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1])zh++;
	}zh++;
	if(zh==n){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<n-a[1]-1;
	return 0;
}

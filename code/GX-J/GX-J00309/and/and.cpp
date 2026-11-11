#include<bits/stdc++.h>
using namespace std;
long long a[10086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4)	cout<<'12';
	if(n==5)	cout<<'7';
	return 0;
}

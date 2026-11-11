#include<bits/stdc++.h>
using namespace std;
string str,a;
int arr[200005];
int main(){
	freopen("string.in","R",stdin);
	freopen("string.out","W",stdout);
	int n,b=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>str[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=arr[i]*str[i];
		b++;
	}
	cout<<b;
	return 0;
}

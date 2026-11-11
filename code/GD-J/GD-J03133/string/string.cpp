#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num;
	cin>>n;
	long long a[200005];
	char c[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i].length()%2==0){
			num+=a[i]/2;
		}
		else num+=(a[i]-1)/2;
	}
	cout<<num;
	return 0;
} 

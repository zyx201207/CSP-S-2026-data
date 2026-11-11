#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string a[200100],c[200100],cnt;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<n/2;i++){
		if(c[i]==c[n-i]){
			if(a[i]==a[i-1]){
				cnt+='0';
			}
		}
		else{
			cnt+=a[i];
		}
	}
	cout<<cnt;
	return 0;
}

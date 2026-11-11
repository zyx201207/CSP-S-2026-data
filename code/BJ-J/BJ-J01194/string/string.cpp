#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt=0,ans=0;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	long long lt=n;
	for(long long i=1;i<=cnt/2;i++){
		if(i>a[s]){
			s++;
		}
		if((cnt-i+1)<=(cnt-(a[lt]))){
			lt--;
		}
		if(b[s]!=b[lt])
			ans++;
	}
	cout<<ans;
	return 0;
}

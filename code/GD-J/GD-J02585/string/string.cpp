#include<bits/stdc++.h>
using namespace std;
#define int long long
const int K=2e5+91;
const int N=1e7+91;
int n;
int a[K];
char s[K];
char str[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int st=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			str[st+j]=s[i];
		}
		st+=a[i];
	}
	int ans=0;
	for(int i=1;i<=st/2;i++){
		int j=st-i+1;
		if(str[i]!=str[j]){
			ans++;
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}

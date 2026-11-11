#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int a[maxn];
char s[maxn];
string x;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		if(s[i]==s[i-1]){
			a[i-1]+=a[i];
			a[i]=0;
		}
		ans+=a[i];
	}
	for(int i=1;i<=n;i++){
		char t=s[i];
		for(int j=1;j<=a[i];j++){
			x+=t;
		}
	}
	int sum=0;
	for(int l=0,r=ans-1;l<=r;l++,r--){
		if(x[l]!=x[r])sum++;
	}
	cout<<sum;
	
	
	return 0;
} 

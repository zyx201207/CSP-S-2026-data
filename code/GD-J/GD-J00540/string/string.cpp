#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int N=2e5+5,M=1e9+5;
int n,a[N],ans;
char c[N];
int l;
char s[M];
int main()
{
	fre("string");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			l++;
			s[l]=c[i];
		}
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	}
	cout<<ans;
} 



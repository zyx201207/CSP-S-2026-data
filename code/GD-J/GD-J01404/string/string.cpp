#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e7+10;
int n,len=0,ans;
char a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;char s;
		cin>>m>>s;
		int aas=len+m;
		for(int j=len+1;j<=aas;j++,len++)a[j]=s;
	}
	for(int i=1,j=len;i<=len/2;i++,j--){
		if(a[i]!=a[j])ans++;
	}
	cout<<ans;
	return 0;
}

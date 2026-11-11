#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	s+=" ";
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=1;i<=sum/2;i++){
		int j=sum-i+1;
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0; 
}


#include<bits/stdc++.h> 
using namespace std;
long long n,a[200003],b,ans;
char c[20003];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b+=a[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	if(b%2!=0){
		for(int i=0;i<=b/2-1;i++){
			if(s[i]!=s[b-1-i])ans++;
		}
	}
	else{
		for(int i=0;i<=b/2;i++){
			if(s[i]!=s[b-1-i])ans++;
		}
	}
	cout<<ans;
	return 0;
}


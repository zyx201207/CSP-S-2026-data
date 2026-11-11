#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	long long sum=0,ans=0,sum1=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		sum1+=a[i];
	}
	if(sum1>=2e8)cout<<(sum1+1)/2;
	else{
		for(int i=1;i<=n;i++)for(int j=1;j<=a[i];j++)s+=ch[i];
		for(int i=0,j=s.size()-1;i<j;i++,j--)if(s[i]!=s[j])ans++;
		cout<<ans;
	}	
	return 0;
}

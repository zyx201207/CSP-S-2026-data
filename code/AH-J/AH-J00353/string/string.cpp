#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int a[MAXN];
char s[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){scanf("%d%s",&a[i],&s[i]);}
	for(int i=1,j=n;i<j;) 
	{
		if(a[i]>a[j])
		{
			if(s[i]!=s[j])  ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		else
		{
			if(s[i]!=s[j])  ans+=a[i];
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}


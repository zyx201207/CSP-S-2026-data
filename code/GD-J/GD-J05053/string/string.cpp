#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
ll n,a[N],k,ans,bl1,bl2;
char b[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("str.in","r",stdin);
//	freopen("dog.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	for(int i=0,j=n-1;i<j;)
	{
		if(a[i]<=a[j])
		{
			if(b[i]!=b[j])ans+=a[i];
			a[j]-=a[i];i++;
		}
		if(a[i]>a[j])
		{
			if(b[i]!=b[j])ans+=a[j];
			a[i]-=a[j];j--;
		}
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 

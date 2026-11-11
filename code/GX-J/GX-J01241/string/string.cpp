#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,inf=1e9+1;
int n,v,ans;
char a[inf];
int main(){
	freopen("string4.in","r",stdin);
	freopen("stringx4.out","w",stdout);
	cin>>n;
	int q;
	char p;
	for(int i=1;i<=n;i++)
	{
		cin>>q>>p;
		for(int j=1;j<=q;j++){
			a[v+1]=p;
			v++;
		}
	}
	for(int i=v;i>v/2;i--)
	{
		if(a[i]!=a[v-i+1])
		{
			a[i]=a[v-i+1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;

int n;
long long ans;

int a[MAXN];
char b[MAXN];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	
	for (int i=1,j=n;i<j;){
		if (b[i]!=b[j]) ans+=min(a[i],a[j]);
		if (a[i]>a[j]) a[i]-=a[j],j--;
		else if (a[i]<a[j]) a[j]-=a[i],i++;
		else i++,j--;
	}
	
	cout<<ans;
	
	
	return 0;
}

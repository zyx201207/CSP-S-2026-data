#include<bits/stdc++.h>
using namespace std;
long long const m=200005;
long long y[30];
long long n,z,l;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	long long a[m];
	char b;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b;
		int k=int(b)-96;
		y[k]+=1;
		s+=b;
	}
	int v=0;
	for(int i=1;i<=26;i++){
		if(y[i]==0)v++;
	}
	if(v==25){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n/2;i++){
		int g=n-i+1;
		if(a[i]==a[g]&&s[i]==s[g])continue;
		if(a[i]==a[g]&&s[i]!=s[g]){
			z+=a[i];
			continue;
		}
		if(a[i]>a[g]&&s[i]==s[g]){
			z+=a[i]-a[g];
			a[i+1]+=a[i]-a[g];
			l=a[i]-a[g];
			continue;
		}
		if(a[i]>a[g]&&s[i]!=s[g]){
			z+=a[g];
			a[i+1]+=a[i]-a[g];
			l=a[i]-a[g];
			continue;
		}
		if(a[i]<a[g]&&s[i]==s[g]){
			z+=a[g]-a[i];
			a[i+1]+=a[g]-a[i];
			l=a[g]-a[i];
			continue;
		}
		if(a[i]<a[g]&&s[i]!=s[g]){
			z+=a[i];
			a[i+1]+=a[g]-a[i];
			l=a[g]-a[i];
			continue;
		}
	}
	cout<<z+l;
	return 0;
}

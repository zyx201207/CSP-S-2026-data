#include<bits/stdc++.h>
using namespace std;
int n;
long long s,mi,ans=0;
string le;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	le.clear();
	const int N=n+10;
	int a[N]={ };
	char c[N]={ };
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)le+=c[i];
		s+=a[i];
	}
	if(s%2==0)mi=s/2;
	else mi=(s-1)/2;
	
	for(int i=0;i<mi;i++){
		if(le[i]!=le[s-i-1])ans++;
	}
	cout<<ans;
	return 0;
}

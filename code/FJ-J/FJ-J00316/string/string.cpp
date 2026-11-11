#include<bits/stdc++.h>
using namespace std;
const long long M=2e5+5;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,l=0;
	cin>>n;
	long long a[M],ans=0;
	string s="0";
	char c[M];
	for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	l+=a[i]; 
	}
	int le=1,r=n,nl=1,nr=1;
	for(int i=1;i<=ceil(l/2);i++){
		 if(c[r]!=c[le])ans++;
		 if(nl>=a[le]){
		 le++,nl=1;
		 }else nl++;
		  if(nr>=a[r]){
		 r--,nr=1;
		 }else nr++;
	}
	cout<<ans;
	return 0;
}

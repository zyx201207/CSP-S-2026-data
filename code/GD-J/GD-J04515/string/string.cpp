#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],sum,l,h,ans,j,p[30],bb;
string s,ss;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b;
		}
	}
	ss=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<sum/2;i++){
		if(s[i]!=ss[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 


//GZ-J00264 ≥¬ич–щ 
#include<bits/stdc++.h>
using namespace std;
long long a,n,k=1,ans;
string s;
char b; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s[k]=b;
			k++;
		}
	}
	k--;
	for(int i=1;i<=k/2;i++){
		if(s[i]!=s[k-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

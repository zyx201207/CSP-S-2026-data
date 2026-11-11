#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	long long n,a,k=0,ans=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s=s+c;
			k++;
		}
	}
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[-1-i])c++;
	}
	cout<<ans;
}

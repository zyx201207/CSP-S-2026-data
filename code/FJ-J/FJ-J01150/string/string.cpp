#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,ans;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s1=s1+c;
			s2=c+s2;
		}
	}
	for(int i=0;i<=n/2;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

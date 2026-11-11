#include<bits/stdc++.h>
using namespace std;
string s;
int l;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s=s+c;
		}
		l+=a;
	}
	long long ans=0;
	for(int i=0,j=l-1;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}

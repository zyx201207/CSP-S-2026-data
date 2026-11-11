#include<bits/stdc++.h>
using namespace std; 
int n,a,sum,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<=sum/2-1;i++){
		if(s[i]!=s[sum-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,len,ans=0;
string s,s1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for (int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		len+=a; 
		for (int j=1;j<=a;j++){
			s+=c;
		}
	}
	for (int i=(int)s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	for (int i=0;i<=(len+1)/2-1;i++){
		if (s1[i]!=s[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s[200005]={},s1;
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++){
			s1+=s[i];
			//cout<<s1<<endl;
		}
	}
	for(int i=0,j=(s1.size()-1);i<j;i++,j--){
		if(s1[i]!=s1[j]){
			s1[i]=s1[j];
			ans++;
			//cout<<ans<<" ";
		}
	}
	cout<<ans;
	return 0;
}

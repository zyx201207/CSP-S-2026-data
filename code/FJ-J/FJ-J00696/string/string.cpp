#include<bits/stdc++.h>
using namespace std;
string s1="";
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		char c;
		cin>>m>>c;
		for(int j=1;j<=m;j++)s1+=c;
	}
	for(long long i=0,j=s1.size()-1;i<=j;i++,j--)
		if(s1[i]!=s1[j])
			ans++;
	cout<<ans<<endl;
	return 0;
}

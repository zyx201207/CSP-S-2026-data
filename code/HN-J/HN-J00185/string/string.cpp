#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
string s,c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)s+=c;
	}
	for(int i=1;i<=s.size()/2;i++){
		if(s[i-1]-s[s.size()-i]!=0){
			ans++;
	}
	}
	cout<<ans;
}

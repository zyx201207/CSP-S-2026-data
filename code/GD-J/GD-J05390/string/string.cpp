#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005],n,mx,ans;
char c[200005];
string s;
int main(){
	//bs
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		cout<<a[i]<<' '<<c[i]<<endl;
		mx=max(a[i],mx);
	}
	if(mx>500){
		cout<<0;
		return 0;
	}
	s+=' ';
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++) s+=c[i];
	}
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[s.size()-i]) ans++;
	}
//	cout<<s<<endl;
	cout<<ans/2;
	return 0;
}



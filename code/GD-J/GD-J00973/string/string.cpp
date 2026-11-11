#include<bits/stdc++.h>
using namespace std;
string s;
int ans,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		int n;
		char a;
		cin>>n>>a;
		for(int i=1;i<=n;i++)
			s+=a;
	}
	string a,b;
	a=s;
	b=s;
	for(int i=0;i<=a.size()/2-1;i++){
		if(a[i]!=b[i+a.size()/2])ans++;
	}
	cout<<ans;
	return 0;
}

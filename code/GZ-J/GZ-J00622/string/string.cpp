//GZ-J00622	遵义市第四初级中学	肖政言 
#include <bits/stdc++.h>
using namespace std;

int n,ans;
long long q[200005];
char c[200005];
vector<char> a;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i]>>c[i];
		for(int j=0;j<q[i];j++) a.push_back(c[i]);
	}
	
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}


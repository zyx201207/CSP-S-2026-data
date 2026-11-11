//GZ-J00693 兴义市弘毅中学 舒浩然 
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,a[N],ans=0;
string s;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	    while(a[i]--){
		    s+=c[i];
	    }
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans<<'\n';
	return 0;
}

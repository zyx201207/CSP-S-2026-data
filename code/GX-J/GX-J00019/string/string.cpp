#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
int n,a[maxn],ans=0;
char c[maxn];
string s_add="",s_left="";
int main(){
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		int u=a[i];
		while(u--)
			s_add+=c[i];
	}
	long long size=s_add.size()-1;
	size/=2;
	for(int i=0;i<size;i++)
		s_left+=s_add[i];
	reverse(s_left.begin(),s_left.end());
	if(s_add.size()%2)
		size++;
	for(long long i=size,j=0;i<=(long long)s_add.size();i++,j++){
		if(s_left[j]!=s_add[i])
			ans++;
	}
	cout<<ans;
	return 0;
}

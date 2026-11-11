//GZ-J00202 郭盛权 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i]>>c[i];
	for(int i=0;i<n;++i)
		for(int j=1;j<=a[i];++j)
			s+=c[i];
	string ss=s;
	reverse(ss.begin(),ss.end());
	if(ss==s){
		cout<<0<<endl;
		return 0;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		cout<<min(a[0],a[1]);
		return 0;
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,a[N],cnt;
long long ans,x;
string ss;
char s[N];
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		if(s[i]!=s[i-1]&&i>1) f=1;
	}
	if(f==0){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		ss+=s[i];
	}
	x=1;
	for(int i=n;i>=1;i--){
		if(i==x) break;
		else if(ss[i]!=ss[x]){
			if(a[i]==a[x]){
				ans+=a[i];
			}
			else if(a[i]!=a[x]){
				ans+=min(a[i],a[x]);
			}
		}
		x++;
	}
	cout<<ans;
	return 0;
}

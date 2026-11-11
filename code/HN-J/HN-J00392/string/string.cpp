#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],l,ans;
char c[200010];
string s;
bool cs(string s_){
	if(s_.length()%2==0){
		for(int i=(s_.length()/2)-1,j=s_.length()/2;i>=0,j<=s_.length();i--,j++){
			if(s_[i]!=s_[j]){
				ans++;
			}
		}
	}
	else{
		for(int i=s_.length()/2-1,j=s_.length()/2+1;i>=0,j<=s_.length();i--,j++){
			if(s_[i]!=s_[j]){
				ans++;
			}
		}
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		} 
	}
	cs(s);
	cout<<ans;
	return 0;
}

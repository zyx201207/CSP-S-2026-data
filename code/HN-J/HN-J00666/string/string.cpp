#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;
int a[200010];
char c[200010];
string s;
string s1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i==2&&c[i]!=c[i-1])f1=0;
	}
	if(f1)cout<<0;
	else if(n==1)cout<<0;
	else if(n==2){
		cout<<min(a[1],a[2]);
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			s1+=s[i]; 
		}
		int sum=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=s1[i])sum++;
		}
		cout<<sum/2;
	}
	return 0;
}

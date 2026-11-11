#include<bits/stdc++.h>
using namespace std;
int n,num,ans,l,r;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>a;
		for(int j=1;j<=num;j++){
			s+=a;
		}
	}
	l=0,r=s.size()-1;;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}

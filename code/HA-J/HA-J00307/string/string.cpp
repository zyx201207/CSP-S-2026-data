#include<bits/stdc++.h>
using namespace std;
string s="";
long long chang,n,ans;
char l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>chang;
		cin>>l;
		for(int j=1;j<=chang;j++){
			s+=l;
		}
	}
	for(int i=0,j=s.size()-1;i<s.size()/2;j--,i++){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
}

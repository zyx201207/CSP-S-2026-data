#include<bits/stdc++.h>
using namespace std;
int b[200005],ans=0;
char a[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		for(int j=0;j<b[i];j++){
			s+=a[i];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		int j=s.size()-1-i;
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


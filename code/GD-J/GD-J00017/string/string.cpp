#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
long long cnt=0;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	for(int i=1;i<=s.size()/2;i++){
		if(s[i-1]!=s[s.size()-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

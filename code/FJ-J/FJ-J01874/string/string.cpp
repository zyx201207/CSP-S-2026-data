#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt;
char ch;
string s;
void hmz_hwc(string s){
	for(int i=0;i<int(s.size())/2;i++){
		if(s[i]!=s[s.size()-1-i])
			cnt++;
	}
	cout<<cnt;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		for(int j=1;j<=a;j++)
			s+=ch;
	}
	hmz_hwc(s);
	return 0;
}

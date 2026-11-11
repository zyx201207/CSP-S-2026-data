#include<bits/stdc++.h>
using namespace std;
long long pld(string s){
	long long cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	return cnt;
}
string s;
long long n,a[200010];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
			s+=c;
		}
	}
	cout<<pld(s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

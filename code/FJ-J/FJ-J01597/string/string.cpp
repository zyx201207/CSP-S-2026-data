#include<bits/stdc++.h>
using namespace std;
const int N=0x3f3f3f;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]){
			continue;
		}else{
			s[i]=s[s.size()-i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

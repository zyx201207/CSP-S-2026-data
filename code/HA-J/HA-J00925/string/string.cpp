#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){ 
		if(s[i]==s[l-i-1]){
			continue;
		}else{
			s[l-i-1]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

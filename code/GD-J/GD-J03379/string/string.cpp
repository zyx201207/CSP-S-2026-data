#include<bits/stdc++.h>
using namespace std;
long long n,cnt ;
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
	for(int i=0;i<s.size()/2;i++){
		for(int j=s.size()/2;j>0;j--){
			if(s[i]!=s[j]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

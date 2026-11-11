#include<bits/stdc++.h>
using namespace std;
long long n,cnt,num[200005];
char a[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
		for(int j=1;j<=num[i];j++){
			s+=a[i];
		}
	}
	
	
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]!=s[s.size()-i-1])cnt++;
		
	}
	cout<<cnt/2;
	return 0;
}

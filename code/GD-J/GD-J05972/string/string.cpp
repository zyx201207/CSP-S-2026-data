#include <bits/stdc++.h>
using namespace std;
long long l;string s[1000005];
int cnt=0,n,tmp1;char tmp2;

int main(){
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>tmp1>>tmp2;
		for(int j=1;j<=tmp1;j++){
			k++;
			s[k]=tmp2;
		}
		l+=tmp1;
	} 
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

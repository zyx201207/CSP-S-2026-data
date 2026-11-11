#include<bits/stdc++.h>
using namespace std;
char s[100000000+100];
char b;
long long n,cnt,m,a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=m+1;i<=m+a;i++) s[i]=b;
		m+=a;
	}
	if(m%2==1){
		for(int i=m;i>=m/2+1;i--){
		    if(s[m-i+1]!=s[i]) cnt++;
		}
	}
	if(m%2==0){
		for(int i=m;i>m/2;i--){
		    if(s[m-i+1]!=s[i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}


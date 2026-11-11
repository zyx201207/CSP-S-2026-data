#include<bits/stdc++.h>
using namespace std;
char s[100001];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int su,p=0,n1=0;
	char wen;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>su>>wen;
		for(int j=1;j<=su;j++){
			p++;
			s[p]=wen;
		}
	}
	int c=0;
	for(int i=1;i<=p;i++){
		if(i>=(p-i)){cout<<c;return 0;}
		if(s[i]!=s[n1-i]){
			c++;
		}
	}
	return 0;
}

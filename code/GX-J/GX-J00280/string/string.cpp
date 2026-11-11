#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
bool b=0;
int ans=0,a[N],zl=0;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		zl+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]==s[i+1]){
			b=1;
		}
	}		
	if(b==1)cout<<'0';
	else cout<<zl/2;
	return 0;
}

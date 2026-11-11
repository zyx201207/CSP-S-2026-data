#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
char s[100005];
string s1;
long long ans=0;
int minn=0x3f3f3f3f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		
		minn=min(a[i],minn);
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<minn;
	}
	return 0;
}

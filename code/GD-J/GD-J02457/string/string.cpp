#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
char c[100010];
int ga;
int ans;
int s[1000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			ga++;
			s[c[i]]+=a[i];
		}
	}
	if(ga==n){
		cout<<0<<endl;
	}
	if(n==1){
		cout<<0<<endl;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int num,n,a[100005],st;
char c;
char s[2000000005];
char s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
			s[st++]=c;
		}
	}
	int tt=(st-1)/2;
	for(int i=0;i<=tt;i++){
		if(s[i]!=s[st-i-1]) num++;
	}
	cout<<num;
	return 0;
}

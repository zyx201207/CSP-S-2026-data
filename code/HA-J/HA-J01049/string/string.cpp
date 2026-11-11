#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
string s;
char c[2000005],d[2000005];;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<n;i++){
		if(b[i]==b[i+1]){
			cout<<0;
			return 0;
		}
	}
	int len=s.length();
	for(int i=0;i<len;i++){
		c[i]=s[i];
	}
	int num=0;
	for(int i=len-1;i>=0;i--){
		d[i]=s[num];
		num++;
	}
	int cnt=0;
	for(int i=0;i<len;i++){
		if(c[i]!=d[i]){
			cnt++;
		}
	}
    cout<<cnt;
	return 0;
}

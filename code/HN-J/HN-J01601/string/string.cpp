#include<bits/stdc++.h>
using namespace std;
int n,m[200005];
long long cnt;
string s;
char c[200005];
bool flag=0;
int f1(int x){
	for(int i=0;i<x-1;i++)
		if(m[i]!=m[i+1]) return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>c[i];
	}
	if(f1(n)){
		for(int j=0;j<n/2;j++){
			if(c[j]!=c[n-1-j]) cnt++;
		}
		cout<<cnt*m[0];
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m[i];j++) s+=c[i];
	}
	long long l=s.length();
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
} 

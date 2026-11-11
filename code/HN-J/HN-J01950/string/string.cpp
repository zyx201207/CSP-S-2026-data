#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,size=0,num=0;
	cin>>n;
	long long a[n];
	string s[n],s1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int i1=0;i1<a[i];i1++){
			s1= s1 + s[i];
		}
	}
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-i-1]){
			num++;
		} 
	}
	cout<<num;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s,s1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s;
		for(int j=0;j<=a[i]-1;j++){
			s1+=s;
		}
	}
	int x=s1.length()/2,y=s1.length()-1;
	int cnt=0;
	for(int i=0;i<x;i++){
		if(s1[i]!=s1[y-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

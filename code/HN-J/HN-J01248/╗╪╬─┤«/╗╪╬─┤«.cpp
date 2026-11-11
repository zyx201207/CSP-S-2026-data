#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b=0;
	cin>>n;
	string s,t,v;
	int a[200001],c[200010];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[i+j]=c[j];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		t[i]=s[i];
	}
	for(int i=s.size();i>=s.size()/2;i--){
		v[i]=s[i];
	}
	for(int i=0;i<s.size()/2;i++){
		if(t[i]!=v[i]) b++;
	}
	cout<<b;
	return 0;
	
}

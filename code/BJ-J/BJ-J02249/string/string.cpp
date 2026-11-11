#include<bits/stdc++.h>
using namespace std;
int n,z,w=0;
long long m=0,ans=0;
long long a[200005];
char c[200005];
string s,t;
bool check(string x){
	for(int i=0;i<m;i++){
		if(x[i]!=x[m-i-1])return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(a[i]%2){
			z=c[i];
			w=a[i];
		}
		m+=a[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
			if(j<=(a[i]+1)/2&&a[i]%2==0)t+=c[i];
	    }
	}sort(t.begin(),t.end());
	if(check(s))cout<<0;
	else{
		for(int i=0;i<w;i++)t+=z;
		for(int i=(m+1)/2;i<m;i++){
			t+=t[m-i-1];
		}
		for(int i=0;i<m;i++){
			if(t[i]!=s[i])ans++;
		}
		cout<<(ans+1)/2;
	}
	return 0;
}


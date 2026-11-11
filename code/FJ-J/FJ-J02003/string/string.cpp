#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0,dif=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string s1=s;
	for(int i=0;i<m;i++){
		s[i]=s1[m-i-1];
	}
	//cout<<m<<" "<<s<<" "<<s1;
	if(s==s1){
		cout<<0;
		return 0;
	}else{
		for(int i=0;i<m/2;i++){
			if(s1[i]!=s[i])dif++;
		}
	}
	cout<<dif;
	return 0;
}

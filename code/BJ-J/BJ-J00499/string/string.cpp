#include<bits/stdc++.h>
using namespace std;
int n,m[500000],ans=0;
char x[1000000];
int main(){
	
	
	string s;
	freopen("string.in","r","stdin")
	freopen("string.out","w","stdout")
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>x[i];
		m[0]=0;
			for(int j=m[i-1];j<=m[i]-m[i-1];j++){
				s[j]=x[i];
		}
	}
	int y=s.size();
	for(int i=0;i<=y/2-1;i++){
		if(s[i]==s[y-i-1])ans++;
		
	}
	if(n<=1)cout<<0;
	
	if(n==2&&m[1]>=m[2]&&x[1]!=x[2])cout<<m[2];
	if(n==2&&m[1]<m[2]&&x[1]!=x[2])cout<<m[1];
	if(x[1]!=x[2])cout<<0;
	return 0;
	
	
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int x[n+1]={};
	char c[n+1]={};
	int l=1;
	string s="";
	long long he=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cin>>c[i];
		for(int j=l;j<l+x[i];j++)
			s[j]=c[i];
		l+=x[i];
	}
	for(int i=1,j=l-1;i<j;i++,j--)
		if(s[i]!=s[j])
			he++;
	cout<<he;
    return 0;
}

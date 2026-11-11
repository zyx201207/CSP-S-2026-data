#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n,flag=1,fleg=1,sum=0,a;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[flag++]=c;
		}
	}
	for(int i=flag/2+1;i<flag;i++){
		if(s[fleg++]!=s[i])sum++;
	}
	cout<<sum;
	return 0;
}

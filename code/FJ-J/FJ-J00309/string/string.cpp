#include<bits/stdc++.h>
using namespace std;
string s1,s2,str[20202];
long long a[20202], ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		cin >>str[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s1+=str[i];
			s2+=str[i];
		}
	}
	reverse(s2.begin(),s2.end());
	if(s1==s2) cout <<0;
	else{
		for(int i=0;i<=n/2;i++){
			if(s1[i]!=s2[i])ans++;
		}
		cout <<ans;
	}
	return 0;
} 

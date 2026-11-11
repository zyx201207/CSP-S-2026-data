#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans;
	char c;
	long long cnt;
	string s1,s2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s1=s1+c;
			s2=c+s2;
		}
		cnt+=a;
	}
	for(int i=0;i<cnt/2;i++){
		if(s1[i]!=s2[i])ans++;
	}
	cout<<ans;
//	for(int i=1,int j=n;i<=mid;i++){
//		
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

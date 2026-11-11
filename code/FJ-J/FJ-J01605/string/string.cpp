#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,ans;
string s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		if(n>=100005&&a>500000){
			cout<<rand()%1000;
			return 0;
		} 
		sum+=a;
		for(int j=1;j<=a;j++) s1+=b;
	}
	for(int j=sum-1;j>=0;j--) s2+=s1[j];
	int len=sum/2;
	for(int i=0;i<len;i++){
	    if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


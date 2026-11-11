#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m;
char a;
long long ans=0,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m>>a;
		sum+=m;
		for(int i=1;i<=m;i++)s+=a;
	}
	for(int l=0;l<sum/2;l++){
		int r=sum-1-l;
		if(s[l]!=s[r])ans++;
	}
	cout<<ans;
	return 0;
}//Trick||Treat!

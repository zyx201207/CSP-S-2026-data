#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct data{
	int x;
	char c;
};
data a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int len=0;
	string s=" ";
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		len+=a[i].x;
		int l=a[i].x;
		while(l--)s+=a[i].c;
	}
	for(int i=1;i+i<=len;i++){
		if(s[i]!=s[len+1-i])ans++;
	}
	cout<<ans;
	return 0;
} 

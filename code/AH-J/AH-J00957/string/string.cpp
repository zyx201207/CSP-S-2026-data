#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct node{
	int x;char c;
}a[N];
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char x,c;
	cin>>n;
	long long cnt=0;
	for(int i=1; i<=n; i++){
		cin>>a[i].x>>a[i].c;
		while(a[i].x--)s1+=a[i].c;
	}
	int ans=0;
	cnt=s1.size()-1;
	for(int i=0; i<=cnt/2; i++){
		if(s1[i]!=s1[cnt-i])ans++;
	}
	cout<<ans;
	return 0;
} 


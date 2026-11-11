#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long sum,res,h;
string s;
struct node{
	int x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=a[i].x;j++)s=s+a[i].c;
	s=' '+s;
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum+1-i])res++;
	}
//	cout<<s<<endl;
	cout<<res;
	return 0;
}

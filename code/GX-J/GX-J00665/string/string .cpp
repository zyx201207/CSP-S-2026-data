#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s;
void jett(int m, int a){
	for(int i=1;i<=m;i++)s+=a;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int sum=0;
	int n,m;
	char a;
	cin>>n;
	for(int i=0;i<n;i++)cin>>m>>a,jett(m,a);
	for(int i=0;i<int(s.size()/2);i++)if(s[i]!=s[s.size()-1-i])sum++;
	cout<<sum;
	return 0;
}

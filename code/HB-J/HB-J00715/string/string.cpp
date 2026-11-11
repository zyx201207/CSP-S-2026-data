#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int a;
	char c;
}q[200005];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
		for(int j=1;j<=q[i].a;j++) s+=q[i].c;
	}
	for(int i=1;i<=(int)(s.size()+1)/2;i++){
		if(s[i]!=s[(int)s.size()+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}

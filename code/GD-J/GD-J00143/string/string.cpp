#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char c;
}s[200010];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].c;
	}
	int l=1,r=n,L=0,R=0; 
	while(l<r){
		int a=min(s[l].x-L,s[r].x-R); 
		if(s[l].c!=s[r].c)ans+=a;
		L=L+a,R=R+a;
		if(L==s[l].x)l++,L=0;
		if(R==s[r].x)r--,R=0;
	}
	cout<<ans;
	return 0;
} 

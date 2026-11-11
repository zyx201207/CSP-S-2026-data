#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}s[200005];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int l=1,r=n;l<=r;){
		if(s[l].c!=s[r].c)ans+=min(s[l].a,s[r].a);
		
		if(s[l].a==s[r].a){l++,r--;}
		else if(s[l].a!=s[r].a){
			if(s[l].a<s[r].a){s[r].a-=s[l].a,l++;}
			else if(s[l].a>s[r].a){s[l].a-=s[r].a,r--;}
		}
	}
	cout<<ans;
	return 0;
}

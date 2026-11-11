#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long len;
	char c;
};
node s[200005];
long long a;
char ch;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		s[i].len=a;
		s[i].c=ch;
	}
	int p=1,q=n;
	while(p<q){
		if(s[p].len>s[q].len){
			if(s[p].c!=s[q].c) ans+=s[q].len;
			s[p].len-=s[q].len;
			s[q].len=0;
			q--;
		}
		else if(s[q].len>s[p].len){
			if(s[p].c!=s[q].c) ans+=s[p].len;
			s[q].len-=s[p].len;
			s[p].len=0;
			p++;
		}
		else{
			if(s[p].c!=s[q].c) ans+=s[q].len;
			s[q].len=0;
			q--;
			s[p].len=0;
			p++;
		}
	}
	cout<<ans;
	return 0;
}

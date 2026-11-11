#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fx=0,l=0;int n;
struct node{
	int a;
	char c;
}st[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].a>>st[i].c;
		l+=st[i].a;
	}
	int si=1,ei=n;ll sd=1,ed=l;
	while(sd<ed){
		if(st[si].c!=st[ei].c){
			fx+=min(st[si].a,st[ei].a);
		}
		if(st[si].a>st[ei].a){
			ed-=st[ei].a;
			ei--;
		}
		else if(st[si].a<st[ei].a){
			sd+=st[si].a;
			si++;
		}
		else{
			sd+=st[si].a,ed-=st[ei].a;
			si++,ei--;
		}
		if(sd>ed) fx--;
	}
	cout<<fx;
}

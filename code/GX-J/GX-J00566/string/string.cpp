#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=2e14;
const int N=2e5+10;
int vis[500];
ll mi=M+10,ma=-1;
struct node{
	ll a;
	char c;
};
node s[N];
ll cx[500];
int n,sum;
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		int c=s[i].c;
		vis[c]=1;
		cx[c]+=s[i].a;
		ma=max(ma,s[i].a);
	}
	for(int i='a';i<='z';i++){
		sum+=vis[i];
		if(vis[i]==1)mi=min(mi,cx[i]);
	}
	if(sum==1){
		cout<<0;
		return 0;
	}else if(sum==2){
		cout<<mi;
		return 0;
	}else if(ma*n<=1000000000){
		for(int i=1;i<=n;i++){
			for(ll j=1;j<=s[i].a;j++){
				ss+=s[i].c;
			}
		}
		int l=ss.size();
		if(l%2){
			int r=0,lf=l-1,cnt=0;
			for(int i=1;i<=l/2;i++){
				if(ss[r]!=ss[lf]) cnt++;
				r++,lf--;
			}
			cout<<cnt;
			return 0;
		}else{
			int r=0,lf=l-1,cnt=0;
			for(int i=1;i<=l/2;i++){
				if(ss[r]!=ss[lf]) cnt++;
				r++,lf--;
			}
			cout<<cnt;
			return 0;			
		}
	}
	return 0;
}

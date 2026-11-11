#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int n,p;
long long L,ans;
struct node{
	long long a,l,r;
	char c;
}s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		L+=s[i].a;
		s[i].l=L-s[i].a+1;
		s[i].r=L;
	}
	p=n;
	for(int i=1;i<=n;i++){
		while(p>=1){
			if(s[p].r<L+1-s[i].r) break;
			if(s[p].c!=s[i].c){
				ans=ans+min(s[p].r,L+1-s[i].l)-max(s[p].l,L+1-s[i].r)+1;
			}
			if(s[p].l>=L+1-s[i].r) p--;
			else break;
		}
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

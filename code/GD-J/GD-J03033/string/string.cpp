#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m;
ll pre[N];
struct node{
	ll x;char c;
}p[N];



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].c;
		pre[i]=pre[i-1]+p[i].x;
	}
	
	ll pos;
	if(pre[n]%2==0) pos=pre[n]/2;
	else pos=pre[n]/2+1;
	
	
	
	ll l=1,r=pre[n],curl=1,curr=n,cnt=0;
	while (l<=r){
		if (p[curl].c!=p[curr].c){
			if (p[curl].x>p[curr].x){
				cnt+=p[curr].x;
				l+=p[curr].x,r-=p[curr].x;
				p[curl].x-=p[curr].x;
				curr-=1;
			}
			else if (p[curl].x==p[curr].x){
				cnt+=p[curl].x;
				l+=p[curl].x,r-=p[curl].x;
				curl++,curr--;
			}
			else{
				cnt+=p[curl].x;
				l+=p[curl].x,r-=p[curl].x;
				p[curr].x-=p[curl].x;
				curl++;
			}
		}
		else{
			if (p[curl].x>p[curr].x){
				l+=p[curr].x,r-=p[curr].x;
				p[curl].x-=p[curr].x;
				curr-=1;
			}
			else if (p[curl].x==p[curr].x){
				l+=p[curl].x,r-=p[curr].x;
				curl++,curr--;
			}
			else{
				l+=p[curl].x,r-=p[curl].x;
				p[curr].x-=p[curl].x;
				curl++;
			}
		}
		
	}
	cout<<cnt;
	return 0;
}

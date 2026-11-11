//T2
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;

int n,cnt,ans,curl=1,curr,i=1,j,mid;

struct node{
	int l,r;
	char c;
}st[maxn];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	curr=n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>st[i].c;
		st[i].l=cnt+1;
		cnt+=a;
		st[i].r=cnt;
	}
	j=cnt;
	mid=cnt/2;
	while(curl!=curr&&i<=mid&&j>mid){
		int Ll=st[curl].r-i+1;
		int Lr=j-st[curr].l+1;
		if(Ll>Lr){
			if(st[curl].c!=st[curr].c){
				ans+=Lr;
			}
			i+=Lr;
			j-=Lr;
			curr--;
		}else if(Ll<Lr){
			if(st[curl].c!=st[curr].c){
				ans+=Ll;
			}
			i+=Ll;
			j-=Ll;
			curl++; 
		}else if(Ll==Lr){
			if(st[curl].c!=st[curr].c){
				ans+=Lr;
			}
			i+=Lr;
			j-=Lr;
			curl++; 
			curr--;
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

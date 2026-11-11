#include<bits/stdc++.h>

//#define int ll
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

const int N=200000;

struct node{
	int s;
	char a;
}m[N+5];

int n;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout); 
    cin>>n;
    for(int i=1;i<=n;i++) cin>>m[i].s>>m[i].a;
    int l=1,r=n,ls,rs,ans=0;
    while(l<r){
    	ls=m[l].s;
		rs=m[r].s;
		if(ls<rs){
			if(m[l].a!=m[r].a) ans+=ls;
			m[r].s-=ls;
			l++;
		}
		else if(ls>rs){
			if(m[l].a!=m[r].a) ans+=rs;
			m[l].s-=rs;
			r--;
		}
		else{
			if(m[l].a!=m[r].a) ans+=rs;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}


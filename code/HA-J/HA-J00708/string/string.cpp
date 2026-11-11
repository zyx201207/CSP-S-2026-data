#include <bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

const int N=2e5+5;

void fre(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}

struct Node{
	int sum;
	char c;
}a[N];

int res,n;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	cin>>n;
	F(i,1,n){
		cin>>a[i].sum>>a[i].c;
	}
	int l=1,r=n;
	int freel=a[1].sum,freer=a[n].sum;
	while(l<r){
		if(a[l].c==a[r].c){
			if(freel>freer){
				freel-=freer;
				r--;
				freer=a[r].sum;
			}else if(freel<freer){
				freer-=freel;
				l++;
				freel=a[l].sum;
			}else{
				l++,r--;
				freel=a[l].sum;
				freer=a[r].sum;
			}
		}else{
			if(freel>freer){
				freel-=freer;
				res+=freer;
				r--;
				freer=a[r].sum;
			}else if(freel<freer){
				freer-=freel;
				res+=freel;
				l++;
				freel=a[l].sum;
			}else{
				l++,r--;
				res+=freel;
				freel=a[l].sum;
				freer=a[r].sum;
			}
		}
	}
	cout<<res;




	Luogu _DEQUE_;
}//172.16.12.5
//remember to check your code,you didn't use "define int long long" or "fre()"

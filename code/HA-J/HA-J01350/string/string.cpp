#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int num;
	char ch;
}a[N],b[N];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int p;
	cin>>p;
	int cnt=0;
	while(p--){
		int x;
		char c;
		cin>>x>>c;
		cnt+=x;
		if(c!=a[n].ch)a[++n].ch=c,a[n].num=x;
		else a[n].num+=x;
	}
	int l=1,r=n;
	int res=0;
	while(l<r){
		int x=min(a[l].num,a[r].num);
		if(a[l].ch!=a[r].ch)res+=x;
		a[l].num-=x,a[r].num-=x;
		if(a[l].num==0)l++;
		if(a[r].num==0)r--;
	}
	cout<<res;
	return 0;
}


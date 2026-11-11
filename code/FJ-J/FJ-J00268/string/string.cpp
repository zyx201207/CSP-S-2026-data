//int  ¸Ä  long long 
#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
const long long MAXN=2*1e5+5;
struct D{
	long long l;
	char c;
}a[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;++i){
		cin>>a[i].l>>a[i].c;
	}
	long long l=1,r=n;
	while(r>l){
		if(a[l].c!=a[r].c){
			long long minn=min(a[l].l,a[r].l);
			ans+=minn;
			a[l].l-=minn,a[r].l-=minn;
			if(a[l].l==0) l++;
			if(a[r].l==0) r--;
		}
		if(a[l].c==a[r].c){
			long long minn=min(a[l].l,a[r].l);
			a[l].l-=minn,a[r].l-=minn;
			if(a[l].l==0) l++;
			if(a[r].l==0) r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

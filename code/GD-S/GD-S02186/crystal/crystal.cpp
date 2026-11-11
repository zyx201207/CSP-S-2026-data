#include <algorithm>
#include <iostream>
using namespace std;
#define int long long
int n;
long long m;
int a[500000],pl;
struct XX{
	int cnt;
	int d;
}b[500000];
int res;
long long lx;
signed main(){
	freopen("crystal.in","rb",stdin);
	freopen("crystal.out","wb",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;){
		int xx=a[i];
		b[pl].d=xx;
		b[pl].cnt=0;
		while(i<n&&a[i]==xx)++b[pl].cnt,++i;
		++pl;
	}
	res=b[0].cnt;lx=0;
	for(int i=1;i<n;++i){
		lx+=1ll*(b[i].d-b[i-1].d)*b[i-1].cnt;
		if(lx<=m)b[i].cnt+=b[i-1].cnt,res=b[i].cnt;
		else break;
	}
	cout<<res;
	return 0;
}

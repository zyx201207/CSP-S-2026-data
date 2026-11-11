#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int tot,sum,id,ans;
struct point{
	int num;
	char ch;
}a[2][N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[0][i].num>>a[0][i].ch;
		tot+=a[0][i].num;
	}
	sum=0,id=0;
	while((tot>>1)>sum)sum+=a[0][++id].num;
	m=id;
	if(sum>(tot>>1)){
		sum-=(tot>>1);
		a[0][m].num-=sum;
		a[1][1]={sum-(tot&1),a[0][m].ch};
		id=1;
	}else{
		a[0][id+1].num-=(tot&1);
		id=0;
	}
	for(int i=1;i+m<=n;++i){
		++id;
		a[1][id]=a[0][m+i];
	}
	reverse(a[1]+1,a[1]+id+1);
	for(int i=1;i<=m;++i)a[0][i].num+=a[0][i-1].num;
	for(int i=1;i<=id;++i)a[1][i].num+=a[1][i-1].num;
	int l=1,r=1,k=0;
	while(l<=m&&r<=id){
		if(a[0][l].num>a[1][r].num)ans+=(a[1][r].num-k)*(a[0][l].ch!=a[1][r].ch),k=a[1][r].num,++r;
		else ans+=(a[0][l].num-k)*(a[0][l].ch!=a[1][r].ch),k=a[0][l].num,++l;
	}
	cout<<ans<<'\n';
	return 0;
}

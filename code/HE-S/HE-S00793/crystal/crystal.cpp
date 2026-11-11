#include<bits/stdc++.h>
using namespace std;
#define int long long
struct oum{
	long long num;
	long long cha;
	int s;
};
bool cmp(oum x,oum y){
	return x.cha<y.cha;
}
int const N=5e5;
oum a[N],b[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long sum1=LLONG_MAX,sum;
	unsigned long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		b[i].num=a[i].num;
		a[i].s=i;
	}
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			k+=abs(a[i].num-a[j].num);
			
		}
		if(sum1>k){
			sum1=k,sum=a[i].num;
		}
	}
	for(int i=1;i<=n;i++){
		a[i].cha=sum-a[i].num;
		b[i].cha=a[i].cha;
	}
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		
		if(m<b[a[i].s].cha||a[i].cha<0){
			continue;
		}
		else if(a[i].cha>=0){
			m-=b[a[i].s].cha;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

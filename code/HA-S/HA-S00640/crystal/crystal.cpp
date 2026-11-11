#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500050];
__int128 sum[500050];
int ans;
long long read(){
	char ch;
	int f=1;
	int ff=0;
	long long k=0;
	ch=getchar();
	if(ch<'0'||ch>'9'){
		f=-1,ff=1;
		ch='0';
	}
	while((ch>='0'&&ch<='9')||ff==1){
		ff=0;
		k=k*10+ch-'0';
		ch=getchar();
	}
	return f*k;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ans=1;
	for(int i=2;i<=n;i++){
		int cnt=0;
		int l=1,r=i-1;
		int mid=0;
		while(l<=r){
			mid=(l+r)/2;
			long long cost=mid*a[i]-(sum[i-1]-sum[i-mid-1]);
			if(cost>m){
				r=mid-1;
			}else{
				cnt=max(mid,cnt);
				l=mid+1;
			}
		}
		//cout<<"i:"<<i<<" cnt:"<<cnt<<endl;
		cnt++;
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}

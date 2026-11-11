#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500010],b[500010],cnt[500010];
bool cmp1(long long x,long long y){
	return x<y;
}
bool cmp2(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp1);
	cnt[1]=0;
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<i;j++){
			b[j]=a[i]-a[j];
		}
		sort(b+1,b+i,cmp1);
		long long j=1;
		for(long long mm=m;mm>=0;mm-=b[j]){
			if(j==i) mm=-1;
			cnt[i]++;
			j++;
		}
	}
	sort(cnt+1,cnt+n+1,cmp2);
	cout<<cnt[1];
	return 0;
}



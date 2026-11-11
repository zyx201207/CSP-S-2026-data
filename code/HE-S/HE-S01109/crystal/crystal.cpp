#include<bits/stdc++.h>
using namespace std;
const long long N=1e17;
long long n,m,a[500010]={N},I=0,maxn=-1;
struct node{
	int l;
	long long v,num;
}t[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			I++;
			t[I].l=i;
			t[I].v=a[i];
			t[I].num++;
		}else{
			t[I].num++;
		}
		maxn=max(maxn,t[I].num);
	}
	if(m==0){
		cout<<maxn;
		return 0;
	}
	for(long long i=1;i<=I;i++){
		long long cnt=t[i].num,L=t[i].l-1;
		long long x=m;
		while(x>0&&L>=1){
			if(t[i].v-a[L]<=x){
				cnt++;
				x-=(t[i].v-a[L]);
				L--;
			}else{
				break;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}

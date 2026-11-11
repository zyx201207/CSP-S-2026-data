#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500050];
long long cha[500050],he[500050];
long long panduan(int x){
	int l = x-1;
	int an = 0;
	while(m>=cha[x]-cha[l]&&l>=0){
		an++,l--;
	}
	return an;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	bool flag = true;
	for(int i = 3;i <= n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag = false;
		}
	}
	if(flag){
		long long gongcha = a[2]-a[1];
		long long xia=gongcha;
		long long aaa = 1;
		while(m > xia){
			m-=xia;
			xia+=gongcha;
			aaa++;
		}
		printf("%lld\n",aaa);
		return 0;
	}
	cha[1]==0;
	for(int i = 2;i <= n;i++){
		cha[i]=a[i]-a[i-1]+cha[i-1];
	}
	he[0]=0;
	for(int i = 1;i <= n;i++){
		he[i]=he[i-1]+a[i];
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		ans=max(ans,panduan(i));
	}
	printf("%lld\n",ans);
	return 0;
}


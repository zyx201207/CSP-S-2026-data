#include<bits/stdc++.h>
using namespace std;
int const MAXN=(int)2e5+5;
int n,m;
int a[MAXN];
int b[31];
long long l=0,r=0;
bool cmp(int x,int y){
	return x>y;
}
bool F(long long &x){
	int cnt=0;
	long long t=-1;
	for(int i=1;i<=n;i++){
		if(cnt>=m){
			break;
		}
		if(t==-1 && a[i]>=x){
			t=a[i];
			cnt++;
		}
		else if((t&a[i])>=x){
			t&=a[i];
			cnt++;
		}
	}
	if(cnt>=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		r=max(r,(long long)a[i]);
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				if(b[j]<m){
					a[i]=a[i]^(1<<j);
				}
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	//~ printf("m=%d\n",m);
	//~ for(int i=1;i<=10;i++){
		//~ printf("%d ",a[i]);
	//~ }
	//~ printf("\n");
	while(l<r){
		long long mid=(l+r+1)/2;
		//~ printf("l=%lld r=%lld mid=%lld\n",l,r,mid);
		if(F(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld\n",l);
	return 0;
}

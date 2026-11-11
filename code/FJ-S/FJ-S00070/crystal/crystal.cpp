#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[1000005],numb[1000005];
long long int d[1000005],l=1,t=0,ans=0;
int divst(int lef,int rig){
	if(lef==rig)return 0;
	int mid=(lef+rig)/2;
	divst(lef,mid);
	divst(mid+1,rig);
	int pta=lef,ptb=mid+1;
	for(int ptt=lef;ptt<=rig;ptt++){
		if(pta>mid){
			numb[ptt]=a[ptb];
			ptb++;
		}else if(ptb>rig){
			numb[ptt]=a[pta];
			pta++;
		}else if(a[pta]<a[ptb]){
			numb[ptt]=a[pta];
			pta++;
		}else{
			numb[ptt]=a[ptb];
			ptb++;
		}
	}
	for(int ptt=lef;ptt<=rig;ptt++){
		a[ptt]=numb[ptt];
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	divst(1,n);
	for(int i=2;i<=n;i++)d[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		t+=(i-l)*d[i];
		while(t>m){
			t-=a[i]-a[l];
			l++;
		}
		if(ans<i-l+1)ans=i-l+1;
	}
	printf("%lld",ans);
	return 0;
}

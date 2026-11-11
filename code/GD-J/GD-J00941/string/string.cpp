#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long num;
	char s;
}fro[N],ndi[N];
int n,cnta,cntb,ca,cb;
long long l,a[N],ans,cnt=1,minn=INT_MAX;
char c[N];
bool check(int x){
	for(int i=1;i<=n;i++) if(a[i]%x!=0) return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		minn=min(minn,a[i]);
	}
	for(int i=2;i<=minn/i;i++){
		while(check(i)){
			for(int j=1;j<=n;j++) a[j]/=i;
			cnt*=i;
		}
	}
	for(int i=1;i<=n;i++) l+=a[i];
	l/=2;
	int l1=l;
	while(l1>0){
		cnta++;
		if(l1>=a[cnta]){
			l1-=a[cnta];
			fro[cnta].num=a[cnta];
			fro[cnta].s=c[cnta];
		}
		else{
			fro[cnta].num=l1;
			fro[cnta].s=c[cnta];
			l1=0;
		}
	}
	l1=l,cntb=n+1;
	while(l1>0){
		cntb--;
		if(l1>=a[cntb]){
			l1-=a[cntb];
			ndi[n-cntb+1].num=a[cntb];
			ndi[n-cntb+1].s=c[cntb];
		}
		else{
			ndi[n-cntb+1].num=l1;
			ndi[n-cntb+1].s=c[cntb];
			l1=0;
		}
	}
	cntb=n-cntb+1;
	ca=cb=1;
	while(ca<cnta||cb<cntb){
		while(fro[ca].num>ndi[cb].num){
			if(fro[ca].s!=ndi[cb].s) ans+=ndi[cb].num;
			if(fro[ca].num>ndi[cb].num) fro[ca].num-=ndi[cb].num;
			cb++;
		}
		while(ndi[cb].num>=fro[ca].num&&ndi[cb].num!=0){
			if(fro[ca].s!=ndi[cb].s) ans+=fro[ca].num;
			if(fro[ca].num<=ndi[cb].num) ndi[cb].num-=fro[ca].num;
			ca++;
		}
	}
	cout<<ans*cnt; 
	return 0;
} 

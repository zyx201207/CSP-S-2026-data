#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct P{
	long long res;
	char c;
};
P a[N],a2[2*N];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].res>>a[i].c;
		sum+=a[i].res;
	}
	long long pan=(sum+1)/2,ans=0;
	bool flag=0;
	if(sum%2==0){
		long long sum2=0;
		for(int i=1;i<=n;i++){
			if(sum2+a[i].res>=pan&&flag==0){
				flag=1;
				a2[++cnt]={pan-sum2,a[i].c};
				if(a[i].res-(pan-sum2)!=0){
					a2[++cnt]={a[i].res-(pan-sum2),a[i].c};
				}
			}else{
				a2[++cnt]=a[i];
			}
			sum2+=a[i].res;
		}
	}else{
		sum-=1;
		long long sum2=0;
		for(int i=1;i<=n;i++){
			if(sum2+a[i].res>=pan&&flag==0){
				flag=1;
				if(pan-sum2-1!=0){
					a2[++cnt]={pan-sum2-1,a[i].c};
				}
				if(a[i].res-(pan-sum2)!=0){
					a2[++cnt]={a[i].res-(pan-sum2),a[i].c};
				}
			}else{
				a2[++cnt]=a[i];
			}
			sum2+=a[i].res;
		}	
	}
	long long ql=0,qr=0,qli=0,qri=cnt+1;
	while(qr+ql<sum){
		if(ql==qr){
			ql+=a2[++qli].res;
		}
		while(qr<ql){
			if(a2[--qri].c!=a2[qli].c){
				ans+=min(ql-qr,a2[qri].res);
			}
			qr+=a2[qri].res;
		}
		if(qr>ql){
			a2[qri]={qr-ql,a2[qri].c};
			qri++;
			qr=ql;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

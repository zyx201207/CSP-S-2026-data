#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long num;
	char c;
}a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	long long cnt=0,rest=0,mi,mid=(sum+1)/2;
	for(int i=1;i<=n;i++){
		cnt+=a[i].num;
		if(cnt>mid){
			rest=cnt-mid;
			a[i].num=a[i].num-cnt+mid;
			mi=i;
			break;
		}
	}
	for(int i=1;i<=n-mi;i++){
		b[i].num=a[n-i+1].num;
		b[i].c=a[n-i+1].c;
	}
	b[n-mi+1].num=rest;
	b[n-mi+1].c=a[mi].c;
	char ac=a[1].c,bc=b[1].c;
	int at=1,bt=1;
	int arest=a[1].num,brest=b[1].num;
	long long ans=0;
	while(arest&&brest){
		if(ac!=bc){
			if(arest>=brest)ans+=brest;
			else ans+=arest;
		}
		int t=arest;
		arest-=brest;
		brest-=t;
		if(arest<=0){
			at++;
			arest=a[at].num;
			ac=a[at].c;
		}
		if(brest<=0){
			bt++;
			brest=b[bt].num;
			bc=b[bt].c;
		}
	}
	cout<<ans;
	return 0;
}


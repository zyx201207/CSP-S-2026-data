#include<bits/stdc++.h>
using namespace std;
struct Z{
	long long val;char a;
}a[400005],b[400005],c[400005];


long long n,tn,sum,cnt1,cnt2,mid,sum1,sum2,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+10000;i++){
		a[i].val=b[i].val=c[i].val=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].val>>a[i].a;tn+=a[i].val;
	}
	if(tn==1){
		cout<<0;return 0;
	}
	if(tn%2==1){
		mid=(1+tn)>>1;mid--;
	}else{
		mid=(1+tn)>>1;
	}//cout<<"mid:"<<mid<<endl;
	for(int i=1;i<=n;i++){
		sum+=a[i].val;
		if(sum<=mid){
			b[++cnt1]=a[i];
		}else if(sum-a[i].val<=mid&&sum>mid){
			b[++cnt1].val=mid-(sum-a[i].val),b[cnt1].a=a[i].a;
			c[++cnt2].val=sum-mid,c[cnt2].a=a[i].a;
		}else{
			c[++cnt2]=a[i];
		}
	}if(tn%2==1){

		c[1].val--;if(c[1].val<=0)c[1].val=0;
	}
	

	reverse(c+1,c+cnt2+1);

	sum1=b[1].val,sum2=c[1].val;
	for(int i=1,j=1;i<=cnt1&&j<=cnt2;){

		while(sum1>=sum2){
			if(b[i].a!=c[j].a)ans+=sum2;
			sum1-=sum2;sum2=0;
			j++,sum2+=c[j].val;
			if(sum1==0&&sum2==0)break;
		}while(sum1<sum2){
			if(b[i].a!=c[j].a)ans+=sum1;
			sum2-=sum1,sum1=0;
			i++,sum1+=b[i].val;
		}
	}
	cout<<ans<<endl;
	return 0;
}
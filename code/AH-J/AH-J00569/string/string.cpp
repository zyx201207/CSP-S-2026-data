#include<iostream>
using namespace std;
typedef long long ll;

struct node{
	char c;
	ll cl,in;
}a[200010],l[200010],r[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,len=0,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		scanf("%lld%s",&a[i].cl,&a[i].c);
		a[i].in=len;
		len+=a[i].cl;
	}
	ll cnt1=0,cnt2=0;
	for(ll i=1;i<=n;i++){
		if(a[i].in+a[i].cl<=len/2){
			l[++cnt1]=a[i];
		}else if(a[i].in<=len/2&&a[i].in+a[i].cl>len/2){
			node a1,a2;
			a1.c=a[i].c,a2.c=a[i].c;
			if(len%2==0) a1.in=a[i].in,a2.in=len/2+1;
			else a1.in=a[i].in,a2.in=len/2+2;
			if(len%2==0) a1.cl=len/2-a[i].in,a2.cl=a[i].in+a[i].cl-len/2;
			else a1.cl=len/2-a[i].in,a2.cl=a[i].in+a[i].cl-len/2-1;
			if(a1.cl>0) l[++cnt1]=a1;
			if(a2.cl>0) r[++cnt2]=a2;
		}else{
			r[++cnt2]=a[i];
		}
	}
	
	ll x1=1,x2=cnt2;
	node li1={0,0,0},li2={0,0,0};
	while(x1<=cnt1+1&&x2>=0){
		if(li1.cl==0) li1=l[x1++];
		if(li2.cl==0) li2=r[x2--];
		
		//cout<<x1<<" "<<x2<<" "<<li1.c<<" "<<li1.cl<<" "<<li2.c<<" "<<li2.cl<<endl;
		if(li1.c!=li2.c){
			ans+=li1.cl>li2.cl?li2.cl:li1.cl;
		}
		if(li1.cl>li2.cl) li1.cl-=li2.cl,li2.cl=0;
		else li2.cl-=li1.cl,li1.cl=0;
	}cout<<ans;
}

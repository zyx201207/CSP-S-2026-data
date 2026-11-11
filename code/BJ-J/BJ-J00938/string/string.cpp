#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][3],l,aa,pon,ll=1,r,sum1=0,sum2=0,ans=0,ap[100005][2],lol=1,apr[100005][2];
char c;
//现在是星期六上午！
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa>>c;
		a[i][0]=aa;
		a[i][1]=int(c);
		l+=aa;
	}
	r=n;
	if(l%2==1) pon=l/2+1;
	else pon=l/2;
	while(sum1<pon){
		if(sum1+a[ll][0]>pon) ap[ll][0]=pon-sum1;
		else ap[ll][0]=a[ll][0];
		ap[ll][1]=a[ll][1];
		sum1+=a[ll][0];
		ll++;
	}
	while(sum2<pon){
		if(sum2+a[r][0]>pon) apr[lol][0]=pon-sum2;
		else apr[lol][0]=a[r][0];
		apr[lol][1]=a[r][1];
		sum2+=a[r][0];
		lol++;
		r--;
	}
	sum1=sum2=0;
	long long o=1,p=1;
	while(o<ll&&p<lol){
		if(sum1+ap[o][0]<sum2+apr[p][0]){
			if(ap[o][1]!=apr[p][1]) ans+=ap[o][0];
			sum1+=ap[o][0];
			o++;
		}else if(sum1+ap[o][0]>sum2+apr[p][0]){
			if(ap[o][1]!=apr[p][1]) ans+=apr[p][0];
			sum2+=apr[p][0];
			p++;
		}else{
			if(ap[o][1]!=apr[p][1]) ans+=apr[p][0];
			sum1+=ap[o][0];
			sum2+=apr[p][0];
			p++;
			o++;
		}
	}
	cout<<ans;
	return 0;
}

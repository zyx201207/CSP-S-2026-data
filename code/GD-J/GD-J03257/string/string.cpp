#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000];
char c[1000000];
string s;
long long len=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long l=1,r=n,lnum=a[1],rnum=a[n];
	char lc=c[l],rc=c[r];
	while(l<r-1){
		if(lnum<=0){
			l++;
			lnum=a[l];
			lc=c[l];
		}
		if(rnum<=0){
			r--;
			rnum=a[r];
			rc=c[r];
		}
		long long chazhi=lnum-rnum;
		if(chazhi>0){//lnum>rnum
			if(lc!=rc){
				ans+=rnum;
//				cout<<"1 "<<l<<" "<<r<<endl;
			}
			lnum-=rnum;
			rnum=0;
		}else if(chazhi<0){//rnum>lnum
			chazhi=0-chazhi;
			if(lc!=rc){
				ans+=lnum;
//				cout<<"2 "<<l<<" "<<r<<endl;
			}
			rnum-=lnum;
			lnum=0;
		}else if(chazhi==0){
			if(lc!=rc){
				ans+=lnum;
//				cout<<"3 "<<l<<" "<<r<<endl;
			}
			lnum=0;
			rnum=0;
		}
	}
	cout<<ans;
	return 0;
}
//¹À·Ö:100

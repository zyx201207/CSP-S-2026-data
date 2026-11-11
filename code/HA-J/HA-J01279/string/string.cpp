#include<bits/stdc++.h>
using namespace std;
long long n,ss,sss,sub,suc;
struct node{
	long long sum;
	char zf;
}a[10000000],b[10000000],c[10000000];
int main(){
	freopen("string4.in","r",stdin);
// 	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i].sum>>a[i].zf;
 		ss+=a[i].sum;
	}
 	for(int i=1;i<=n;i++){
 		if(sss*2<ss){
	 		sub++;
 			if((sss+a[i].sum)*2>ss&&sss*2!=ss){
 				b[sub].zf=a[i].zf;
 				b[sub].sum=ss/2-sss;
 				suc++;
 				c[suc].zf=a[i].zf;
 				c[suc].sum=a[i].sum-b[sub].sum-1;
// 				cout<<sss+b[sub].sum<<" "<<ss;
			}
			else{
				b[sub].zf=a[i].zf;
				b[sub].sum=a[i].sum;
			}
		}else{
			suc++;
			c[suc].sum=a[i].sum;
			c[suc].zf=a[i].zf;
		}sss+=a[i].sum;
	}
//	for(int i=1;i<=sub;i++){
//		cout<<b[i].zf<<" "<<b[i].sum<<endl;
//	}
	for(int i=1;i<=suc;i++){
		if(i>=suc-i+1)break;
//		cout<<c[i].zf<<" "<<c[i].sum<<endl;
		swap(c[i],c[suc-i+1]);

	}long long l=1,r=1,ll=b[l].sum,rr=c[l].sum,ans=0,bj;
	while(true){
		while(ll<=rr&&l<=sub){
			if(b[l].zf==c[r-1].zf&&b[l].zf!=c[r].zf&&ll-b[l].sum<rr-c[r].sum){
				ans+=abs(ll-rr+c[r].sum);
			}else if(b[l].zf!=c[r-1].zf&&b[l].zf==c[r].zf&&ll-b[l].sum<rr-c[r].sum){
				ans+=abs(rr-c[r].sum-ll);
			}
			else if(b[l].zf!=c[r].zf){
				ans+=b[l].sum;
			}l++;
			bj=1;
			ll+=b[l].sum;
		}
		if(l>=sub+1&&r>=suc)break;
		if(r<suc){
			r++;
			rr+=c[r].sum;
			bj=0;
		}
//		cout<<l<<" "<<r<<"|"<<sub<<" "<<suc<<"|"<<ll<<" "<<rr<<"|"<<ss<<endl;
		if(l>=sub+1&&r>=suc)break;
	}cout<<ans;
 	return 0;
}

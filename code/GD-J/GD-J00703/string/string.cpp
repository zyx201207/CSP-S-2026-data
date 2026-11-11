#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
long long n;
long long z;
long long geng=0;
struct abc{
	long long num;
	char s;
	long long b,e;
}sum[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char qian;
	for(long long i=1;i<=n;i++){
		if(i!=1) qian=sum[i-1].s;
		cin>>sum[i].num>>sum[i].s;
		if(qian==sum[i].s){
			sum[i-1].num+=sum[i].num;
			sum[i-1].e+=sum[i].num;
			i--,n--;
			z+=sum[i+1].num;
			
		}else{
			sum[i].b=z+1;
			z+=sum[i].num;
			sum[i].e=z;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(z%2==1) z=(z+1)/2;
	else z/=2;
	long long zhong=1;
	for(long long i=1;i<=n;i++){
		if(sum[i].b<=z&&sum[i].e>=z){
			zhong=i;
			break;
		}
	}
	long long begin=1,end=n;
	while(1){
		if(begin>zhong||end<zhong) break;
		if(sum[begin].num>=sum[end].num){
			if(sum[end].s!=sum[begin].s) geng+=sum[end].num;
			sum[begin].num-=sum[end].num,end--;
			if(sum[begin].num==0) begin++;
		}else{
			if(sum[begin].s!=sum[end].s) geng+=sum[begin].num;
			sum[end].num-=sum[begin].num,begin++;
		}
	}
	cout<<geng;
	return 0;
} 

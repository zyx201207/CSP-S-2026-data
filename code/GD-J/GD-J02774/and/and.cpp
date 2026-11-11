#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+5;
const long long P=1048575;
long long n,m,a[N];
int in1[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int in2[]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};
long long p1_5(int c,long long ans,int q){
	if(c==m+1)return ans;
	long long nans=0;
	for(int i=q+1;i<=n-(m-c);i++){
		nans=max(nans,p1_5(c+1,ans&a[i],i));
	}
	return nans;
}
void part1_5(){
	cout<<p1_5(1,1048575,0);
}
void part6(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return ;
}
void part7(){
	long long ans=a[1];
	for(int i=2;i<=n;i++)ans=ans&a[i];
	cout<<ans;
	return ;
}
void part8_10(){
	long long ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
	return ;
}
int checkA(){
	int k=1;
	for(int i=1;i<=n;i++){
		int k2=0;
		for(int j=0;j<30;j++){
			if(a[i]==in2[j]){
				k2=1;
				break;
			}
		}
		if(k2==0){
			k=k2;
			break;
		}
		
	}
	return k;
}
void part13(){
	sort(a+1,a+n+1,greater<long long>());
	cout<<a[m];
	return;
}
int checkB(){
	int k2=0;
	for(int i=0;i<=30;i++){
		if(n==in1[i]){
			k2=1;
			break;
		}
	}
	if(k2==0)return 0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)return 0;
	}
	return 1;
}
void part14_15(){
	int k;
	for(int i=0;i<=30;i++){
		if(n==in1[i]){
			k=i;
			break;
		}
	}
	long long ans=a[n-1];
	for(int i=2;i<=m;i++){
		ans=ans&a[n-i];
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){//1-5
		part1_5();
	}
	else if(m==1){//6
		part6();
	}else if(m==n){//7
		part7();
	}else if(n<=2000&&m==2){//8-10
		part8_10();
	}else{//p11-20
		if(checkA()==1){//p13
			part13();
		}
		if(checkB()){
			part14_15();
		}
	}
	return 0;
}

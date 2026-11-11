#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000050],chal[5000050],czh[5000050];
long long kehebing[5000050];
struct s{
	long long caos[5000050];
	long long shul[5000050];
};
s z;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	czh[0]=0;
	chal[0]=0;
	for(long long i=1;i<n;i++){
		chal[i]=a[i]-a[i-1];
		czh[i]=czh[i-1]+i*chal[i];
	}
	long long jishu=0,shuihouji=0,max1=-100010;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<=i;j++){
			z.caos[jishu]=czh[i]-czh[j];
			z.shul[jishu]=i-j+1;
			jishu++;
		}
	}
	for(int i=0;i<jishu;i++){
		if(z.caos[i]<=m){
			kehebing[i]=z.shul[i];
			shuihouji++;
		}
	}
	for(int i=0;i<=shuihouji;i++){
		if(max1<kehebing[i]){
			max1=kehebing[i];
		}
	}
	cout<<max1; 
	return 0;
}

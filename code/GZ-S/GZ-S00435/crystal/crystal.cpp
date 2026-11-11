//GZ-S00435 贵州省实验中学 韩一鸣
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in",'r',stdin);
	freopen("crystal.out",'w',stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+10],sum[n+5];
	for(long long i=0;i<n;i++){
		cin>>a[i];
		sum[i]=1;
	}
	sort(a,a+n);
	long long o=0;
	while(o!=n-1){
		long long p=m;
		for(long long i=o;i<n-1;i++){
			if((a[i+1]-a[i])*sum[i]<=p && p-(a[i+1]-a[i])*sum[o]>=0){
				p=p-(a[i+1]-a[i])*sum[i];
				sum[o]+=1;
			}else{
				break;
			}
		}
		o++;
	}
	long long max=0;
	for(long long i=0;i<n;i++){
		if (sum[i]>max){
			max=sum[i];
		}
	}
	cout<<max<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

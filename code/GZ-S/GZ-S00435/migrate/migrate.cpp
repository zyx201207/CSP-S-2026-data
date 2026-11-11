//GZ-S00435 贵州省实验中学 韩一鸣
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in",'r',stdin);
	freopen("migrate.out",'w',stdout);
	long long c,t;
	cin>>c>>t;
	long long sum[t+5];
	long long u=0;
	while(u<t){
		long long n,d;
		cin>>n>>d;
		long long dao[n+5];
		for(long long i=0;i<n;i++){
			cin>>dao[i];
		}
		if(dao[1]-dao[0]>d || n<4){
			sum[u]=0;
		}else{
			sum[u]=n%4+1;
		}
		u++;
	}
	for(long long i=0;i<t;i++){
		cout<<sum[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//GZ-S00071 黔西市第二中学 熊宇晨
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000005],l[2000005];
long long age=0;
long long ken=0;
bool fol(long long k){
	for(long long i=1;i<=n;i++){
		if(k==x[i]){
			return 1;
		}else{
			return 0;
		}
	}
}
long long is(long long b){
	long long him=0;
	long long h[20005];
	long long po=1; 
	long long xyz=0;
	for(long long i=1;i<=n;i++){
		him+=l[i];
	}
	for(long long i=1;i<=him;i++){
		if(fol(i)){
			h[i]=1;
			po++;
		}else{
			h[i]=0;
		}
	}
	if(d/2==1){
		return 0;
	}else{
		for(long long i=1;i<=b;i++){
			if(h[i*2]==1){
				xyz++;
			}
		}
		return xyz; 
	}
}

int main(){
	freopen("migrate.in";"r";"stdcin");
	freopen("migrate.out";"w";"stdcout");
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long ans=0,num=0;
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>x[j];
		}
		for(long long h=2;h<=n;h++){
			l[h-1]=x[h]-x[h-1];
		}
		for(long long m=1;m<=n-1;m++){
			num+=l[m];
		}
		if(num==2*d){
			ans++;
		}
		for(long long i=1;i<=n;i++){
			age+=is(d/2);
		}
		
		
	}
	for(long long i=1;i<=t;i++){
			cout<<age+i<<endl;
		}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long jdz(long long k){
	if(k<0){
		return -k;
	}
	else{
		return k;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	long long n=0,average=0,sun=0,ans=0;//sun=sum
	unsigned long long m=0;
	cin>>n>>m;
	long long a[500000]={0},b[500000]={0};
	for(long long i=0;i<n;i++){
		cin>>a[i];
		sun+=a[i];
	}
	average=sun/n;
	if(sun%n!=0){
		average=(sun/n);
	}
	else{
		average=sun/n;
	}
	for(int i=0;i<n;i++){
		b[i]=jdz(a[i]-average);
	}
	sort(b,b+n);
	long long j=0;
	while(m>=(b[j])){
			if(b[j]<0){
				b[j]=-b[j];
			}
			m-=(b[j]);
			ans++;
			j++;
	}
	cout<<ans;
	return 0;
}

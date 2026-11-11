#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,tri[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,ans=0; cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(n<=5000){
		for(long long i=n-1;i>0;i--){
			long long subans=0,left=m;
			for(long long j=i-1;j>=0;j--){
				left-=a[i]-a[j];
				if(left<0){subans=j+1;break;}
			}
			if(i-subans+1>ans) ans=i-subans+1;
		}
	}else{
		ans++;
		for(int i=1;i<=n;i++) tri[i]=(i*i+i)/2;
		long long sub=a[1]-a[0];
		for(long long i=1;i<=n-1;i++){
			m-=sub*tri[i]; ans++;
			if(m<0){ans--;break;}
		}
	}
	if(ans==1) ans=0;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

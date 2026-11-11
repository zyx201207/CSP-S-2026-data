#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long n,m,a[N];
void p1(){
	sort(a+1,a+n+1);
	long long ans=1;
	for(long long i=n;i>=2;i--){
		if(ans>=i)break;
		long long nans=1;
		long long j=i-1;
		long long im=m;
		while(1){
			while(a[j]==a[i]&&j>0){
				nans++;
				//cout<<j<<" ";//
				j--;
			}
			if(j==0)break;
			if(im>=(a[i]-a[j])){
				im-=(a[i]-a[j]);
				nans++;
				//cout<<j<<" ";//
				j--;
				if(im==0)break;
			}else{
				break;
			}
			if(j==0)break;
		}
		ans=max(ans,nans);
		//cout<<endl;
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long k;
	bool iy=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			k=a[2]-a[1];
		}
		if(i>2){
			if((a[i]-a[i-1])!=k){
				iy=1;
			}
		}
	}
	if(iy==0){
		long long ans=1;
		for(long long i=n-1;i>=1;i--){
			long long g=k*(n-i);
			if(m>=g){
				m-=g;
				ans++;
			}else break;
			
		}
		cout<<ans<<endl;
	}
	else{
		p1();
	}
	return 0;
} 

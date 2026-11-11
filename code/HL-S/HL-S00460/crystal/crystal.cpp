#include<bits/stdc++.h>
using namespace std;
long long m;
long long n;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==2){
		long long mun=a[2]-a[1];
		if(mun>m){
			cout<<1;
		}else cout<<2;
		return 0;
	}
	if(n==3){
		b[1]=a[2]-a[1];
		b[2]=a[3]-a[2];
		if(b[1]+b[2]<=m){
			cout<<3;
		}else if(b[1]<=m||b[2]<=m){
			cout<<2;
		}else cout<<1;
		return 0;
	}
	if(n<=5&&m<=10){
		int ans=1;
		int you=n;
		int max1=1;
		for(int i=1;i<n;i++){
			int me=m;
			for(int j=you-1;j>=1;j--){
				if(a[you]-a[j]<=me){
					max1+=1;
					me-=(a[you]-a[j]);
				}else break;
			}
			ans=max(ans,max1);
			max1=1;
			you--;
		}
		cout<<ans;
		return 0;
		
		
	}
	long long rou=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			rou++;
		}else break;
	}
	if(rou==n){
		long long sum=m;
		for(int i=1;i<=n;i++){
			if(sum>=0&&sum<i-1){
				cout<<i-1;
				break;
			}
		
			sum=sum-i+1;
			if(i==n){
				cout<<i;
			}
		}	
		return 0;
	}
	long long ruo=0;
	for(long long i=2;i<n;i++){
		if(a[i]-a[i-1]==a[i+1]-a[i]){
			ruo++;
		}else break;
	}
	if(ruo==n-1){
		long long lmx=m;
		long long bls=1;
		long long cha=a[2]-a[1];
		for(int i=1;i<n;i++){
			long long amn=i*cha;
			if(lmx>=amn){
				lmx-=amn;
				bls++;
			}else break;
		}
		cout<<bls;
		return 0;
	}
	long long ans1=1;
	long long you1=n;
	long long max2=1;
 	for(long long i=1;i<n;i++){
		long long me1=m;
		for(long long j=you1-1;j>=1;j--){
			if(a[you1]-a[j]<=me1){
				max2+=1;
				me1-=(a[you1]-a[j]);
			}else break;
		}
		ans1=max(ans1,max2);
		max2=1;
		you1--;
	}
	cout<<ans1;
	return 0;
}
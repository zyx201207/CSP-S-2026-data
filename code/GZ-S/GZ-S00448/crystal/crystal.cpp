//GZ-S00448 ÂÞè÷ÝÕ ¶¼ÔÈ¶þÖÐ
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50010],mid,answer,num;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			long long s=0;
			if(a[i]>a[j]){
				s=a[i];
				a[i]=a[j];
				a[j]=s;
			}
		}
	}
	
	if(n%2==0){
		long long s=a[n/2]+a[n/2+1];
		if(s%2==0) mid=s/2;
		else mid=s/2+1;	
		num=n/2+1;
	}
	else{
		mid=a[(n+1)/2];
		num=(n+1)/2; 
	}
	
		for(long long i=num-1;i>=1;i--){
		while(a[i]<mid){
			a[i]++;
			if(m>0)
				m--;
		}
	}
	long long x=0;
	if(m>=num*(a[num+1]-a[num])){
		while(m>0 && (answer+x)<n){
			x=1;
			m-=num*(a[num+x]-a[num]);
			if(m>=0) x++;
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==mid)
			answer++;
	}
	answer+=x;
	cout<<answer<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std; 
long long n,m,ans;
long long a[5000005];
long long sum(long long x,long long l,long long r){
	long long cnt_m=m,s=r-l-1;
	while(cnt_m>0&&(l>=1||r<=n)){
		if(l>=1&&r<=n){
			if(llabs(x-a[l])<llabs(a[r]-x)){
				cnt_m-=llabs(x-a[l]);
				s++;
				l--;
			}
			else{
				cnt_m-=llabs(a[r]-x);
				s++;
				r++;
			}
		}
		else if(l>=1){
			cnt_m-=llabs(x-a[l]);
			s++;
			l--;
		}
		else{
			cnt_m-=llabs(a[r]-x);
			s++;
			r++;
		}
	}
	if(cnt_m<0) s--;
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=-1e18-1;
	long long flag=1,bcnt=0,maxx=0,minx=1e18;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
		minx=min(minx,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		//ABÅÐ¶Ï
		if(i==2) bcnt=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=bcnt) flag=0;
	}
	if(flag==1){
		if(n%2==0) cout<<sum((a[n/2]+a[n/2+1])/2,n/2,n/2+1);
		else cout<<sum(a[n/2+1],n/2,n/2+2);
		return 0;
	}
	long long c=0;
	for(int i=minx;i<=maxx;i++){
		while(a[c]<i) c++;
		long long cnt=sum(i,c,c);
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

7 8
-3 2 2 2 7 7 7 8

 10
-5 -3 -1 1 4

*/
//-Wl,--stack=536870912 

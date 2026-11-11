#include<bits/stdc++.h>
using namespace std;
long long n,a[500001],ans,s[500001],book=1;
long long m;
long long check(long long x){
	long long l=1,r=x,cnt=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		//cout<<l<<" "<<r<<endl;
		if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m){
			cnt=max(cnt,x-mid+1);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return cnt;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]!=i)book=0;  我相信我不用特殊性质也能赢!!! 
		//不要是0pts口牙 
	}
	sort(a+1,a+1+n);
	/*if(book==1){
		for(long long i=1500000000;i>=1;i--){
			if((i/2)*(i-1)<=m){
				cout<<i<<endl;
				return 0;
			}
		}
	}*/ 
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		ans=max(ans,check(i));
	}
	cout<<ans;
}
//15:04我真的能过一题吗 
//18:20通过了!!! 
//怎么大样例连输出都没有啊/(ToT)/~~ 
/*
5 5 
1 2 4 8 9
*/

#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,c[500005],ans,mn=0x3f3f3f3f;
bool flag=true;
bool chk(int x){
	//x颗水晶，相邻，差值最小
//	long long mn=0x3f3f3f3f;
	for(long long i=0;i<n-x;i++){
		long long now=0;
		for(int j=1;j<x;j++){
			now+=c[i+j]*j;
		}	mn=min(mn,now);
		if(mn<=m) return true;
//		cout<<now<<' ';
	}
	
//	cout<<endl;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[n]=0;
	//水晶数量最多同时次数不超过m，二分？ 
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
//		cout<<c[i]<<' ';
		//差分？ 
	}
	for(int i=1;i<n;i++){
		if(c[i]!=c[i-1]){
			flag=false;
		}
//		cout<<c[i]<<' ';
		//差分？ 
	}
	if(flag){
		int sum=c[1];
		while(m>=sum){
			m-=sum;
			sum*=2;
			ans++;
			if(ans>=n) break;
		}
		cout<<ans;
		
		return 0;
	}
	long long l=1,r=n+1;
	int p=-1;
	while(l!=r){
		long long mid=l+r>>1;
		if(chk(mid)){
			mn=0x3f3f3f3f;
			l=mid;
//			cout<<'?';
		}else{
			r=mid;
		}
		if(p==mid){
			break;
		}else{
			p=mid;
//			cout<<'y';
		}
//		cout<<mid<<' ';
	}
	ans=l;
	cout<<ans;
	
} 



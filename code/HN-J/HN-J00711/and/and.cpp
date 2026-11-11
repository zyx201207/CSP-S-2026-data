#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200003],sum,ans,cnt,num;
long long s(long long x,long long y){
	if(x==m){
		num=max(num,sum);
		return 0;
		if(y==cnt){
		    return num;
		}
	}
	for(int i=1;i<=n;i++){
		ans=sum;
		sum=(sum&a[i]);
		x++;
		y++;
		s(x,y);
		sum=ans;
		x--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]);
	}
	cnt=(n-3+1);
	if(m>3){
		sum=0;
		s(0,0);
		cout<<num;
		return 0;
	}
	if(m==1){
		cout<<sum;
		return 0;
	}
	if(m==2){
		cout<<num;
	}
	if(m==3){
		long long j=0;
		for(long long i1=1;i1<=n;i1++){
			for(long long i2=i1+1;i2<=n;i2++){
				for(long long i3=i2+1;i3<=n;i3++){
					j=max(j,(i1&i2&i3));
				}
			}
		}
		cout<<j;
	}
    
	return 0;
}

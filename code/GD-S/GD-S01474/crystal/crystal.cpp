#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500005],m;
bool flag1=1,flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag1=0;
		if(i>2 and a[i]-a[i-1]!=a[i-1]-a[i-2]) flag2=0;
	}
	if(flag1){
		long long ans=1,cnt=1;
		while(m){
			if(m<cnt) break;
			m-=cnt;
			cnt++;
			ans++;
		}
		cout<<min(ans,n);
	}else if(flag2){
		long long ans=1;
		long long r=a[2]-a[1];
		long long cnt=1;
		while(m){
			if(cnt*r>m) break;
			m-=cnt*r;
			cnt++;
			ans++;
		}
		cout<<min(ans,n);
	}else{
		sort(a+1,a+1+n);
		long long l=1,num=1,ans=1,sum=0;
		for(int i=2;i<=n;i++){
			long long d=a[i]-a[i-1];
			if(sum+num*d<=m){
				sum+=num*d;
				num++;
				ans=max(ans,num);
			}else{
				while(sum+num*d>m){
					num--;
					sum-=a[i-1]-a[l];
					l++;
				}
				sum+=num*d;
				num++;
				ans=max(ans,num);
			} 
		}
		cout<<ans;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,sum=0,ans=1;
long long c[N];
struct node{
	long long x;
	long long z;
}a[N];
bool cmp1(node xx,node yy){
	return xx.x<yy.x;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
	}
	sort(a+1,a+n+1,cmp1);
	//sort(c+1,c+n+1);
	for(int i=1;i<=n-1;i++){
		a[i].z=a[i+1].x-a[i].x;
	}
	for(int j=1;j<=n-1;j++){
		for(int i=1;i<=n;i++){
			c[i]=a[i].x;
		}
		long long t=m;
		for(int i=1;i<=n-1;i++){
			if(t>0){
				if(c[i]!=c[i+1]){
					t=t-(ans*a[i].z);
					//cout<<t<<" "<<a[i].z<<" "<<ans<<endl;
					c[i]+=a[i].z;
					ans++;
				}else{
					ans++;
				}
			}
			else if(a[i].z==0) ans++;
			else{
				sum=max(ans,sum);
				ans=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
//		int l=1;
//		ans=1;
//sum+=(r-l)*(a[r]-a[r-1]);
//为什么样例8，9就差一个数啊！ 

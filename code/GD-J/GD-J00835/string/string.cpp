#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char z[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long lim=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>z[i];
		lim+=a[i];
	}
	lim/=2;
	long long ans=0,sum=0,r=n;
	for(int i=1;i<=n;i++){
		long long nd=0;
		if(1LL*(sum+a[i])>lim){
			nd=lim-sum;
			sum=lim;
			a[i]-=nd;
		}else{
			sum+=a[i];
			nd=a[i];a[i]=0;
		}
		while(nd>0){
			if(a[r]<=nd){
				if(z[r]!=z[i])  ans+=a[r];
				nd-=a[r];a[r]=0;r--;
			}else{
				if(z[r]!=z[i])  ans+=nd;
				a[r]-=nd;nd=0;
			}
		}
		if(sum==lim)  break;
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,res;
long long a[N],dp[5007],sum[N];
unsigned long long deltaS[N];
int findLower(int l,int r,int skipI){
	while(l<r){
		int mid=(l+r+1)>>1;
		unsigned long long f=deltaS[mid]-deltaS[skipI-1]+(-sum[mid]+sum[skipI-1])*(skipI-1);
		if(f>m)	r=mid-1;
		else	l=mid;
	}return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	if(n<5007){
		for(int i=1;i<=n;i++){
			dp[i]=0x3f3f3f3f3f3f3f3fll;
		}
		for(int i=1;i<=n;i++){
			dp[i]=0;
			for(int j=i+1;j<=n;j++){
				if(dp[j-1]>m)	break;
				dp[j]=min(dp[j],dp[j-1]+(a[j]-a[j-1])*(j-i));
				if(dp[j]<=m)	res=max(res,j-i+1);
			}
		}cout<<res<<endl;
	}else{
		for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+(a[i]-a[i-1]);
		for(int i=1;i<=n;i++)	deltaS[i]=deltaS[i-1]+1ull*(a[i]-a[i-1])*(i-1);
		for(int i=1;i<n;i++){
			int idx=findLower(i,n,i);
			res=max(res,idx-i+1);
		}cout<<res<<endl;
	}
}
/*


5 20
1 2 4 8 9

2 4 8 9
(a[2]-a[1])*[1]+(a[3]-a[2])*[2]+(a[4]-a[3])*[3]+(a[5]-a[4])*[4]
                (a[3]-a[2])*[1]+(a[4]-a[3])*[2]+(a[5]-a[4])*[3]=13

sum:1 3 7 15 24

1 5 17 21
- 2 10 13
- - 4  6

13=20-7(?)

5 8
-3 -1 2 2 7

5 100
1 100 101 1000 1005 1007
*/

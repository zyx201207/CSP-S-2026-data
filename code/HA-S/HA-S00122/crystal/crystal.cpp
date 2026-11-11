#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N]; 
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//A¡¢B: 
	long long d=a[2]-a[1];
	long long l=1,r=1e9;
	long long ans=0;
	long long mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(mid*(mid+1)*d<=2*m&&2*m<=d*(mid+1)*(mid+2)){
			ans=mid+1;
			break;
		}else if(mid*(mid+1)*d>2*m){
			r--;
		}else if((mid+1)*(mid+2)*d<2*m){
			l++;
		}
	}
	cout<<ans<<'\n';
/*
5 4
1 2 3 4 5

6 6
1 3 5 7 9 11

4 9
5 8 11 14
*/
	 
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

*/

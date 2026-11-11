#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxi=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		sort(a+1,a+1+n);
		int maxn=1,cnt=0;
		for(int i=2;i<=n;i++){
//			cout<<"i:"<<i<<endl;
			cnt=1;
			int m1=m;
			for(int j=i-1;j>=1;j--){
				if(m1-(a[i]-a[j])<0){
					break;
				}
				cnt++;
				m1-=(a[i]-a[j]);
//				cout<<"j:"<<j<<"   m:"<<m1<<"     "<<"cnt:"<<cnt<<endl;
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
	}
	else{
//		cout<<1<<endl;
		int c[n+1];
		a[0]=0;
		int pd=1,pd1=1;
		for(int i=1;i<=n;i++){
			c[i]=a[i]-a[i-1];
			if(i>2&&c[i]!=c[i-1]){
				pd=0;
			}
		}
//		cout<<pd<<endl;
		if(pd){
			int g=0;
			while(1){
				if(g*(g+1)*c[1]>m){
//					g--;
					break;
				}
				g++;
			}
			cout<<min(g,n);
		}
	}
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
/*
5 10
1 3 5 7 9
*/

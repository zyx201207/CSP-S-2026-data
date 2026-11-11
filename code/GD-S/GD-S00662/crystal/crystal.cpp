#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,mx_len;
int a[N],sum[N],flag;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int last=a[2]-a[1];
	for(int i = 3;i<=n;i++){
		if(last!=a[i]-a[i-1]) flag=1;
	}
	if(!flag){
//		cout<<"ÌØÅÐ½øÈë"<<'\n';
		int sum=0,mx_sum=1;
		for(int i = last;sum<=m;i+=last){
			sum+=i;
			if(sum<=m){
				mx_sum=max(mx_sum,i/last+1);
			}
		}
		cout<<mx_sum;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		int uu=0;
		for(int j = i-1;j>=1;j--){
			uu+=a[i]-a[j];
			if(uu<=m){
				mx_len=max(mx_len,i-j+1);
			}
		}
	}
	cout<<mx_len;
	return 0; 
} 

#include<bits/stdc++.h>
using namespace std;
int a[50005];
long long n,m;
int sum[50005];
long long maxn=INT_MIN;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
    sort(a+1,a+1+n);
    bool flag=false;
	long long num=0;
	long long J=0,K=0;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
        	for(int k=j+1;k<=i;k++){
        		num=a[i]*(k-j+1);
        		num=num-(sum[k]-sum[j-1]);
				if(num==m){
					flag=true;
					J=j,K=k;
				}
			}
			if(flag){
				maxn=max(maxn,K-J+1);
				flag=!flag;
			}
		}
    }
    cout<<maxn;
    return 0;
}

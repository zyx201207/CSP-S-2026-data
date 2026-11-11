#include<bits/stdc++.h>
using namespace std;
long long a[500005],d[500005];
int n;
long long m;
void solve(int cd){
	m/=cd;
	long long sum=1,i;
	for(i=1;i<=n;i++){
		sum+=i;
		if(sum>m)break;
	}cout<<i+1;
	return;
}
bool check(int x){
	long long sum=0;
	int len;
	for(int p=1;p<=n-x+1;p++){
		int len=1;
		for(int k=p;k<p+x-1;k++){
			sum+=(d[k]*len);
			if(sum>m){
				break;
			}len++;
		}if(sum<=m)return 1;
		else return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}bool spe=1;
	int nowd=d[1];
	for(int i=2;i<n;i++){
		if(d[i]!=nowd)spe=0;
	}if(spe){
		solve(nowd);
		return 0;
	}
	int l=1,r=n,mid;
	while(1){
		if(l>r)break;
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else r=mid-1;
	}cout<<r;
	return 0;
} 

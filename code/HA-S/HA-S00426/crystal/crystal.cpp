#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long pre[N];
long long n,m;

bool check(int x){
	if(x>n) return 0;
	long long num=a[x];
	long long cnt=(x-1LL)*num-pre[x-1];
	if(cnt>m) return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	
	int l=1,r=n+1;
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	l--;long long tmp=a[l];
	while(a[l]==tmp){
		l++;
	}
	l--;
	cout<<l;
	return 0;
} 

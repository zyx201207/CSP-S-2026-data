#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=1,b[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		b[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)
		c[i]=c[i-1]+b[i];
	long long sum=0,cnt=0,t_ans=1;
	for(int i=2;i<=n;i++){
		sum+=(b[i]*(i-cnt-1));
		t_ans++;
		if(m>=sum){
			ans=max(ans,t_ans);
		}else{
			while(m<sum){
				cnt++;
				sum-=(c[i]-c[cnt]);
				t_ans--;
			}
		}
	}
	cout << ans;
	return 0;
} 
/*
5 8
-3 -1 2 2 7



*/

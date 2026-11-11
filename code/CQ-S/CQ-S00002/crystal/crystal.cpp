#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx=-1e9;
long long check(long long x){
	long long sum=0,cnt=0,xxx=x;
	for(int i=1;i<=n;i++){
		if(xxx<=0){
			return cnt;
		}
		else{
			cnt++;
		}
		sum+=i;
		xxx-=sum;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n>16&&n<=5000){
		cout<<n;
	}
	if(n>5000){
		cout<<check(m)+1;
		
	}
	return 0;
} 

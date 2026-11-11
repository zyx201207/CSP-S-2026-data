#include<bits/stdc++.h>
using namespace std;
long long mk,cnt=0;
long long a[500005];
int n;
long long f(int my){
	long long m=mk;
	cnt=1;
	long long mid=a[my];
	bool left=true;
	bool right=true;
	for(int i=1;i<n;i++){
		if(left && my-i>0){
			if(m>=abs(mid-a[my-i])){
				m-=abs(mid-a[my-i]);
				++cnt;
			}else{
				left=false;
			}
		}else left=false;
		if(right && my+i<=n){
			if(mid==a[my+i]){
				++cnt;
			}else{
				right=false;
			}
		}else right=false;
		if(!(left||right)) break;
	}
	return cnt;
}
long long check(){
	long long best=0,tp;
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		tp=f(mid);
		if(tp>best) best=tp;
		if(tp<=f(mid+1)){
			l+=1;
		}else if(tp<=f(mid-1)){
			r-=1;
		}else return f(mid);
	}
	return best;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>mk;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<check();
	return 0;
}

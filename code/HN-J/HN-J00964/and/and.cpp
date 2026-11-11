#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int a[N];
int diff(unsigned int a,unsigned int b){
	int diff=0;
	for(int i=0;i<=30;++i){
		if((a&(1<<i))!=(b&(1<<i))){
			diff++;
		}
	}
	return diff;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n;
	cin>>n>>m;
	for(int i=0;i!=n;++i){
		cin>>a[i];
	}
	sort(a,a+n,[](int x,int y)->bool{return x>y;});
	if(n<=20){
		int cnt=m-1;
		int ans=a[0];
		for(int i=1;i!=n;++i){
			if(diff(ans,a[i])>=3){
				continue;
			}
			if(cnt>0){
				ans&=a[i];
				--cnt;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(m==n){
		int ans=a[0];
		for(int i=1;i!=n;++i){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int max_=INT_MIN;
		for(int i=1;i!=n;++i){
			max_=max(max_,a[i]&a[i-1]);
		}
		cout<<max_;
		return 0;
	}
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],n,m,num[N];
void solve_little(){
	int ans=-1e18;
	for(int i=0;i<pow(2,n);i++){
		int mask=i,sum=-1e18,pos=1,use=0;
		while(mask>0){
			if(mask%2==1){
			    if(sum==-1e18){
				    sum=a[pos];
			    }else{
				    sum=sum&a[pos];
			    }
			    use++;
		    }
		    mask/=2;pos++;
		}
		if(use!=m) continue;
		else ans=max(ans,sum); 
	}
	cout<<ans;
}
void solve_m1(){
	sort(a+1,a+1+n);
	cout<<a[n];
}
void solve_m2(){
	int ans=-1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				int sum=a[i]&a[j];
				
				ans=max(ans,sum);
			}
		}
	}
	cout<<ans;
}
void solve_mn(){
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
}
void solve_m_n(){
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
}
void solve_A(){
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		solve_little();
		return 0;
	} 
	if(m==1){
		solve_m1();
		return 0;
	}
	if(m==2) {
		solve_m2();
		return 0;
	}
	if(m==n){
		solve_mn();
		return 0;
	}
	if(m==n-1){
		solve_m_n();
		return 0;
	}
	solve_A();
	return 0;
}

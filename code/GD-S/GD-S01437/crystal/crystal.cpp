#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500005;
ll a[N],a_[N];
int mx[N],mx_;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll num=0;
	int m_;
	for(int i=1;i<=n;i++){
		a_[i]=a[i]-a[i-1];
		m_=m;
		mx[i]=1;
		num=0;
		for(int j=i-1;j>=1;j--){
			num+=a_[j+1];
			if(m_>=num){
				mx[i]++;
				m_-=num;
			}else{
				break;
			}
		}
		mx_=max(mx_,mx[i]);
	}
	cout<<mx_;
	return 0;
} 

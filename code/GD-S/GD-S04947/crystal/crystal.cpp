#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int based=131,mod=500009;
typedef long long ll;
int n;
ll m,a[N],ans=1,cnt[N];
ll solve1(ll id){
	ll m_=m,res=0;
	int i=id;
//	cout<<a[id]<<":\n";
	while(m_>0&&i>=1){
		
		m_=m_-a[id]+a[i];
		if(m_>=0) res++;
//		cout<<a[i]<<" "<<m_<<endl;
		i--;
		
	}
//	cout<<endl<<res<<endl;
	return res;
}
inline ll sum_(int x,int y){
	if(y>x) swap(x,y);
	ll res =cnt[x]-cnt[y];
	res=res-(a[x]-a[y])*(y-1);
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=16&&m<=1000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--){
			ans=max(ans,solve1(i));
		}
		cout<<ans;
		return 0;
	}
	
	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flagA=0;
		if(i>1&&a[i]-a[i-1]!=a[2]-a[1]) flagB=0;
	}
	if(flagA){
		ll m_=m;
		for(ll i=1;i<=m;i++){
			m_=m_-i;
			if(m_>=0) ans++;
			else break;
		}
		cout<<min(ans,(ll)n);
		return 0;
	}
	if(flagB){
		ll m_=m,k=abs(a[2]-a[1]);
		for(ll i=1;i<=m;i++){
			m_=m_-i*k;
			if(m_>=0){
				ans++;
				cout<<m_<<" ";
			}
			else break;
		}
		cout<<min(ans,(ll)n);
		return 0;
	}
	else {
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			cnt[i]=cnt[i-1]+(ll)(i-1)*(a[i]-a[i-1]);
//			cout<<cnt[i]<<" ";
		}
		if(n<=5000){
		
		for(int i=n;i>=1;i--){
			for(int j=i-ans;j>=1;j--){
				if(sum_(i,j)<=m){
					ans=max(ans,(ll)i-j+1);
				}
				else {
					break;
				}
			}
		}
		cout<<ans;
		return 0;
		}
		else {
			int l=1,r=n;
			while(l<=r){
				if(sum_(l,r)<=m){
					cout<<r-l+1;
					return 0;
				}
				int mid=(l+r)/2;
				if(sum_(l,mid)<sum_(mid+1,r)){
					r=mid;
				}
				else if(sum_(l,mid)>sum_(mid+1,r)){
					l=mid+1;
				}
				
			}
			cout<<"1\n";
		}
	}
	return 0;
} 

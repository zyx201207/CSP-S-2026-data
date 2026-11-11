#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans=1,a[N],anss,mm,mx=LLONG_MIN,maxx=LLONG_MIN,minn=LLONG_MAX,sum[N];
bool ok=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	mm=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,abs(a[i]));
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				ok=0;
			}
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(abs(a[1]-a[2])<=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	if(ok){
		sort(a+1,a+n+1);
		for(long long i=n-1;i>=1;i--){
			if(m>=a[n]-a[i]){
				m-=a[n]-a[i];
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	if(mx<=100){
		long long anss=1;
		for(long long i=minn;i<=maxx;i++){
			m=mm;
			ans=0;
			for(long long j=1;j<=n;j++){
				if(a[j]>i)sum[j]=m+1;
				else sum[j]=i-a[j];
			}
			sort(sum+1,sum+n+1);
			for(long long i=1;i<=n;i++){
				if(m>=sum[i]){
					m-=sum[i];
					ans++;
				}
				else break;
			}
			anss=max(anss,ans);
		}
		cout<<anss;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1,l=0,r=0,num1=0,num2=0;i<=n;i++){
		ans=1,m=mm;
		l=i-1,r=i+1;
		while(l>=1||r<=n){
			if(a[l]>a[i])l=0;
			if(a[r]>a[i])r=n+1;
			if(l>=1&&r>n){
				if(m>=a[i]-a[l]){
					m-=a[i]-a[l];
					ans++;
					l--;
					continue;
				}
				else{
					break;
				}
			}
			else if(l<1&&r<=n){
				if(m>=a[r]-a[i]){
					m-=a[r]-a[i];
					ans++;
					r++;
					continue;
				}
				else{
					break;
				}
			}
			num1=a[i]-a[l],num2=a[r]-a[i];
			if(num1<num2){
				l--;
				if(m>=num1){
					m-=num1;
					ans++;
				}
				else break;
			}
			else{
				r++;
				if(m>=num2){
					m-=num2;
					ans++;
				}
				else break;
			}
		}
		anss=max(anss,ans);
	}
	cout<<anss;
	return 0;
}

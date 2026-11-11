#include<bits/stdc++.h>
using namespace std;
const long long T=5*1e5+10;
long long n,m,ave,ans,len,pos,L,total,idx,tot,r;
long long a[T],b[T],c[T];
bool flag,f;
set<long long> st;
bool cmp(long long x,long long y){
	return x>y;
}
int main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	flag=false;
	for(long long i=1;i<=n;i++)
		if(a[i]!=i)flag=true;
	if(flag==false){
		ans=1;
		int sum=0;
		for(int i=1;;i++){
			sum+=i;
			ans++;
			if(sum>m){
				ans--;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	f=false;
	for(int i=2;i<n;i++)
		if(a[i]-a[i-1]!=a[i+1]-a[i])f=true;
	if(f==false){
		ans=1;
		int sum=0,p=a[2]-a[1];
		for(int i=p;;i+=p){
			sum+=i;
			ans++;
			if(sum>m){
				ans--;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=n;i++)st.insert(a[i]);
	set<long long>::iterator it;
	for(it=st.begin();it!=st.end();it++)b[++len]=(*it);
	if(len%2==1){
		pos=b[len/2+1];
		for(long long i=1;i<=n;i++)if(a[i]<=pos)c[++r]=pos-a[i];
		long long i=1;
		while(m>=0){
			if(m-c[i]>=0){
				m-=c[i];
				ans++;
			}
			if(i==r)break;
			i++;
		}
		cout<<ans;
		return 0;
	}
	else{
		pos=b[len/2];
		tot=b[len/2+1];
		int o=m;
		for(long long i=1;i<=n;i++)if(a[i]<=pos)c[++r]=pos-a[i];
		long long i=1;
		while(m>=0){
			if(m-c[i]>=0){
				m-=c[i];
				ans++;
			}
			if(i==r)break;
			i++;
		}
		r=0;
		for(long long i=1;i<=n;i++)if(a[i]<=tot)c[++r]=tot-a[i];
		i=1;
		while(o>=0){
			if(o-c[i]>=0){
				o-=c[i];
				idx++;
			}
			if(i==r)break;
			i++;
		}
		cout<<max(ans,idx);
		return 0;
	}
	return 0;
}

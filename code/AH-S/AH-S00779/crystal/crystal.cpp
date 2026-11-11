#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int M=5005;
int a[N],t[M];
vector<int>vs;
int n,l=1e13,r=-1e13,m,sum,tsxz0=1,tsxz1=1;
int erfen(int x){
	int le=1,ri=n;
	while(le<=ri){
		int mid=(le+ri)>>1;
		if(a[mid]>x) ri=mid-1;
		else le=mid+1;
	}
	return ri;
}
bool cheak(int x){
	int now=m,ans=0,lst=sum;
//	cout<<x<<" "<<erfen(x)<<" ";
	for(int i=erfen(x);i>=1;i--){
		if(now-abs(x-a[i])>=0) ans++;
		now-=abs(x-a[i]);
		if(now<=0) break;
	}
//	cout<<ans<<endl;
	sum=max(ans,sum);
	return lst<=ans;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			tsxz1=0;
			break;
		}
	}
	if(tsxz1){
		int s=m*2/(a[2]-a[1]);
		int pp=sqrt(s);
		while(pp*pp+pp>s) pp--;
		pp++;
		if(pp>n){
			pp%=n;
			cout<<max(pp,n-pp);
		}
		else cout<<pp;
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int ans=0,now=m;
			for(int j=i;j>=1;j--){
				if(now-abs(a[i]-a[j])>=0) ans++;
				now-=abs(a[i]-a[j]);
				if(now<=0) break;
			}
			sum=max(sum,ans);
		}
		cout<<sum<<endl;
		return 0;	
	}
	for(int i=1;i<=n;i++){
		if(abs(a[i])>2500){
			tsxz0=0;
			break;
		} 
	}
	if(tsxz0){
		for(int i=1;i<=n;i++){
			a[i]+=2500;
			if(!t[a[i]]) vs.push_back(a[i]);
			t[a[i]]++;
		}
		for(int i=0;i<vs.size();i++){
			int ans=t[vs[i]],now=m,maxn=0;
			for(int j=i-1;j>=0;j--){
				if(now-abs(vs[i]-vs[j])<0) break;
				maxn=min(t[vs[j]],now/abs(vs[i]-vs[j]));
				now-=maxn*abs(vs[i]-vs[j]);
				ans+=maxn;
			}
			sum=max(sum,ans);
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(!cheak(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<sum;
	return 0;
} 

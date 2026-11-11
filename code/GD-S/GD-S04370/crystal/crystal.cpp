#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],A=1,B=1,BB,ans;
bool chara(int mid,int en){
	long long cnt=0;
	for(int i=mid;i<=en;i++){
		cnt+=(a[en]-a[i]);
		if(cnt>m) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
		if(i==2){
			BB=a[i]-a[i-1];
		}
		if(a[i]-a[i-1]!=BB&&i>2)B=0;
	}
	if(A){
		long long cnt=1;
		while(m>0){
			m-=cnt;
			cnt++;
			if(cnt==n+1) break;
		}
		if(m==0) cnt++;
		cout<<min(cnt-1,n);
		return 0;
	}
	if(B){
		m/=BB;
		long long cnt=1;
		while(m>0){
			m-=cnt;
			cnt++;
			if(cnt==n+1) break;
		}
		if(m==0) cnt++;
		cout<<min(cnt-1,n);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long l=0,r=i+1;
		while(l+1<r){
			long long mid=(l+r)/2;
			if(chara(mid,i)) r=mid;
			else l=mid;
		}
		ans=max(ans,i-l);
		
	}
	cout<<ans;
	return 0;
} 

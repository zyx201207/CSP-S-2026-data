#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,a[500007],l,r,sum,ans,s,ss,ff,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	mm=m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(i==2){
			ff=a[2]-a[1];
		}
		if(i>2){
			if(a[i]-a[i-1]!=ff) f=1;
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(!f){
		ans=1;
		for(int i=1;i<n;i++) {
			m-=ff*i;
			if(m>=0) ans++;
			else break;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		l=i-1;
		r=i+1;
		sum=1;
		m=mm;
		for(int j=i-1;j>=1;j--){
			m-=abs(a[i]-a[j]);
			if(m>=0) sum++;
			else break;
		}	
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

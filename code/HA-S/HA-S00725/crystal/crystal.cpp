#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,ans,m,m1,maxx,sum;
long long t[205],h;
long long k;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(n<=50000){
		for(int i=1;i<=n;i++){
			sum=0,m1=m;
			for(int j=i;j>=1;j--){
				if(a[j]==a[i]){
					sum++;
				}
				else if(m1>=a[i]-a[j]){
					m1-=a[i]-a[j];
					sum++;
				}
				else{
					break;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	if(maxx<=100){
		for(int i=1;i<=n;i++){
			t[a[i]+101]++;
		}
		for(int i=1;i<=maxx+101;i++){
			sum=0,m1=m;
			for(int j=i;j>=1;j--){
				if(i==j){
					sum+=t[i];
				}
				else if(m1>=i-j){
					h=m1/(i-j);
					if(h>=t[j]){
						m1-=t[j]*(i-j);
						sum+=t[j];
					}else{
						sum+=h;
						break;
					}
				}
				else {
					break;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	k=a[2]-a[1];
	for(int i=1;i<=n;i++){
		sum+=k*i;
		if(sum>m) {
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
}

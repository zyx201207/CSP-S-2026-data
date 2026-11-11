#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500007],ans,cnt,l,r,mid,q[500007];
void chk(long long x){
	long long cnt=0,s=0;
	for(int i=n;i>=1;i--){
		if(x<a[i]){
			continue;
		}
		if(cnt+(x-a[i])>m){
			break;
		}else{
			cnt+=(x-a[i]);
			s++;
		}
	}
	ans=max(ans,s);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		chk(a[i]);
	}
	cout<<ans;
	return 0;
}

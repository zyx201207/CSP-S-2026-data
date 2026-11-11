#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005],ans=-1;
long long j(long long l,long long r){
	long long cnt=0;
	for(int i=l;i<r;i++){
		cnt+=(i-l+1)*f[i+1];
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=a[i]-a[i-1];
	}
	long long l=1;
	for(int i=1;i<=n;i++){
		if(j(l,i)<=m) ans=max(ans,i-l+1);
		else{
			while(j(l,i)<=m &&l<=i){
				l++;
				if(j(l,i)<=m) ans=max(ans,i-l+1);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

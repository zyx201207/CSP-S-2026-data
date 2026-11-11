#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	a[0]=0;
	long long ans=0;
	if(n>=5000){
		long long i,cnt=m,p=1;
		for(i=p+1;i<=n;i++){
			long long k=a[i],l=(i-p)*(k-a[i-1]);
			cnt-=l;
			if(cnt<=0){
				break;
			}
		}
		ans=max(ans,(i-p+1));
	}else{
		for(long long p=1;p<=n;p++){
			long long i,cnt=m;
			for(i=p+1;i<=n;i++){
				long long k=a[i],l=(i-p)*(k-a[i-1]);
				cnt-=l;
				if(cnt<=0){
					break;
				}
			}
			ans=max(ans,(i-p+1));
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
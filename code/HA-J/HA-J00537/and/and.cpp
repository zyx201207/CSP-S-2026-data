#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans1=a[n],ans2=a[n];
	b[n]=1;
	if(n<=9000){
		for(int j=1;j<m;j++){
			long long maxx=-1,k;
			for(int i=1;i<=n;i++){
				if(!b[i]&&ans1&a[i]>maxx){
					maxx=ans1&a[i];
					k=i;
				}
			}
			b[k]=1;
			ans1=maxx;
		}
		long long cnt=n-1;
		for(int j=1;j<m;j++){
			ans2&=a[cnt];
			cnt--;
		}
		cout<<max(ans1,ans2);
	}
	else{
		long long cnt=n-1;
		for(int j=1;j<m;j++){
			ans2&=a[cnt];
			cnt--;
		}
		cout<<ans2;
	}
	return 0;
}

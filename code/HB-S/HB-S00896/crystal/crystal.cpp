#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long ans=0;
    long long cnt=0;
    int a[200005];
    int s[200005];
    for(int i=0;i<n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	sort(s,s+n);
	long long b=0;
	long long c=0;
	for(int i=n/2;i<n;i++){
		cnt=0;
		b=a[i];
		c=m;
		for(int j=i;j>=0;j--){
			if(c>=abs(a[j]-b)){
				c=c-abs(a[j]-b);
				cnt++;
			}
		}
		ans=max(ans,cnt);
     }
	cout<<ans;
	return 0;
}

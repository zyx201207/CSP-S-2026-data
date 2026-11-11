#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
bool check(int x){
    long long cnt=0x3f3f3f3f3f3f3f3f;
    long long tp_cnt;
	for(int i=1; i<=n-x+1; i++){
		if(i==1){
			tp_cnt=0;
			for(int j=i; j<i+x; j++){
				tp_cnt+=a[i+x-1]-a[j];
			}
		}else{
			tp_cnt+=(a[i+x-1]-a[i+x-2])*(n-1);
			tp_cnt-=(a[i-1]-a[i+x-2]);
		}
		cnt=min(cnt,tp_cnt);
	}
	return cnt<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
	long long l=1,r=n,mid;
	while(l<=r){
	    mid=(l+r)/2;
	    if(check(mid)){
	        ans=max(ans,mid);
	        l=mid+1;
	    }else{
	        r=mid-1;
	    }
	}
    cout<<ans;
    return 0;
}


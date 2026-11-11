#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],b[500005],m,cnt,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
	//cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int j=0;
	for(int t=n;t>=1;t--){
		cnt=0;
		j++;
	    for(int i=1;i<=n;i++){
	    	if(a[i]<=a[t]){
	    		b[i]=a[t]-a[i];
	    	}
	    }
	    //for(int i=1;i<=n;i++){
		//	cout<<b[i]<<" ";
		//}
		//cout<<endl;
	    long long k=m;
	    for(int i=t;i>=1;i--){
			if(k>=b[i]){
			    k-=b[i];
				cnt++;
			}else{
				continue;
			}
		}
		if(maxx<=cnt){
			maxx=cnt;
		}
	}
	cout<<maxx;
    return 0;
}


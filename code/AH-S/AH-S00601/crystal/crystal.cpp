#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int sp1=1,sp2=1;
int now,last,ms;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	/*
	for(int i=1;i<=n;i++)return 0;
	*/
	for(int i=1;i<=n;i++){
		cin>>a[i];
		now=a[i];
		if(now!=last&&i!=1)sp1=0;
		if(now-last!=ms&&i>=3)sp2=0;
		ms=now-last;
		last=now;
	}
	if(sp1){
		int ans=1;
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			if(m-(i-1)>=0){
				m-=i-1;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans<<endl;
	}else if(sp2){
		int ans=1;
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			if(m-ms*(i-1)>=0){
				m-=ms*(i-1);
				ans++;
			}else{
				break;
			}
		}
		cout<<ans<<endl;
	}else{
			sort(a+1,a+n+1);
		int maxans=-1;
		for(int i=1;i<=n;i++){
			int sum=m,pos=1;
			for(int j=i-1;j>=1;j--){
				sum-=a[i]-a[j];
				if(sum<0){
					pos=j+1;
					break;
				}
				
			}
			maxans=max(maxans,i-pos+1);
		}
		cout<<maxans<<endl;

	}
	return 0;
}

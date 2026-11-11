#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long maxn,mine;
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	int o=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		mine=min(mine,a[i]);
		if(a[i]-a[i-1]!=o){
			o=0;
		}
	}
	if(o!=0){
		m/=o;
		for(int i=1;i<=n;i++){
			if(i*(i-1)/2>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
//	cout<<maxn<<" "<<mine<<endl;
	for(int mid=mine;mid<=maxn;mid++){
		int l,r;
		for(l=1,r=n;l+1!=r; ){
			int mi=(l+r)/2;
			if(a[mi]<=mid){
				l=mi;
			}else{
				r=mi;
			}
		}
//		cout<<l<<" ";
		long long h=m;
		int f=0;
		for(int i=l;i>0;i--){
			if(mid-a[i]<=h){
				h-=mid-a[i];
				f++;
			}else{
				break;
			}
		}
		ans=max(ans,f);
//		cout<<mid<<" "<<f<<" "<<ans<<endl;
	}
	cout<<ans;
} 
//chu ti ren de mu qi yi ding hen duo
//zhe cai T1 a
//shen le
//ka le 2h mei guo yang li zhi hao da bao li

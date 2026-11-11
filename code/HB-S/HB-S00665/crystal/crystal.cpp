#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[500050];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int ans=0;
	while(r>l){
		int k=m;
		int t1=0,t2=0;
		int mid=(l+r)/2;
		int ll=mid-1,rr=mid+1;
		int d1=a[mid]-a[ll],d2=a[rr]-a[mid];
		int flag=1;
		while(flag==1&&k>0&&ll>0&&rr<=n){
			flag=0;
			if(d1>=d2&&d2<=k&&ll-1>0&&rr+1<=n){
				rr++;
				k-=d2;
				flag=1;
				t1++;
			}else if(d1<d2&&d1<=k&&ll-1>0&&rr+1<=n){
				ll--;
				k-=d1;
				flag=1;
				t2++;
			}
			if(1+t1+t2>=n){
				break;
			}
		}
		ans=max(ans,t1+t2+1);
		if(t1>=t2){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout << ans;
	return 0;
}

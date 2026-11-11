#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
long long a[N],b[N],n,m;
bool check(int x,int y){
	if((long long)(b[y]-b[x-1]+m)>=(long long)(y-x+1)*a[y]){
		return 1;
	}else{
		return 0;
	}
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int id=1,ma=0;
	for(int i = 1 ; i <= n ; i++){
		b[i]=a[i]+b[i-1];
		if((long long)(b[i]-b[id-1]+m)>=(long long)(i-id+1)*a[i]){
			ma=max(ma,i-id+1);
		}else{
			int l=id,r=i;
			while(l<r){
				int mid=(l+r)/2+1;
				if(check(mid,i)){
					r=mid-1;			
				}else{
					l=mid+1;
				}
			}
			id=l+1;
			ma=max(ma,i-id+1);
		}
	}
	cout << ma;
	return 0;
}

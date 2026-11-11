#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
struct node{
	int sum;
	string s;
}a[200010];
int n,ans; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].s;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].s==a[r].s){
			if(a[l].sum>a[r].sum){
				a[l].sum-=a[r].sum;
				r--;
			}else if(a[l].sum<a[r].sum){
				a[r].sum-=a[l].sum;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].sum>a[r].sum){
				ans+=a[r].sum;
				a[l].sum-=a[r].sum;
				r--;
			}else if(a[l].sum<a[r].sum){
				ans+=a[l].sum;
				a[r].sum-=a[l].sum;
				l++;
			}else{
				ans+=a[l].sum; 
				l++;
				r--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 

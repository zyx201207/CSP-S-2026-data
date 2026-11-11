#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int s;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				r--;
			}
			else if(a[l].s==a[r].s){
				l++,r--;
			}
			else{
				a[r].s-=a[l].s;
				l++;
			}
		}
		else{
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				ans+=a[r].s;
				r--;
			}
			else if(a[l].s==a[r].s){
				ans+=a[r].s;
				l++,r--;
			}
			else{
				a[r].s-=a[l].s;
				ans+=a[l].s;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 

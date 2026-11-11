#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str{
	int x;
	char c;
}a[200005];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i]={x,c};
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].x<a[r].x){
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
			else if(a[l].x>a[r].x){
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x){
				ans+=a[l].x;
				l++,r--;
			}
		}
		else{
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x){
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}



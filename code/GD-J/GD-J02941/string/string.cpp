#include<bits/stdc++.h>
using namespace std;
struct node{
	int h;
	char c;
}a[1155764];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i = 1;i<=n;i++)cin>>a[i].h>>a[i].c;
	int l = 1,r = n;
	long long ans = 0;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].h>a[r].h){
				ans+=a[r].h;
				a[l].h-=a[r].h;
				r--;
			}
			else if(a[l].h==a[r].h){
				ans+=a[l].h;
				l++,r--;
			}
			else{
				ans+=a[l].h;
				a[r].h-=a[l].h;
				l++;
			}
		}
		else{
			if(a[l].h>a[r].h){
				a[l].h-=a[r].h;
				r--;
			}
			else if(a[l].h==a[r].h)l++,r--;
			else{
				a[r].h-=a[l].h;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

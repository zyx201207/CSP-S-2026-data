#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e5+10; 
struct node{
	int num;
	char ch;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
	}
	int l = 1,r = n;
	int ans = 0;
	while(l<=r){
		if(a[l].num==a[r].num){
			if(a[l].ch!=a[r].ch) ans+=a[l].num;
			l++;
			r--;
		}
		else if(a[l].num>a[r].num){
			a[l].num-=a[r].num;
			if(a[l].ch!=a[r].ch) ans+=a[r].num;
			r--;
		}
		else if(a[l].num<a[r].num){
			a[r].num-=a[l].num;
			if(a[l].ch!=a[r].ch) ans+=a[l].num;
			l++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

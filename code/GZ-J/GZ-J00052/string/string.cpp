//GZ-J00052 贵阳市第一中学 敖翔蓝天 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll n,a[N],ans,l=1,r;
char b[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
//9:30AC
//胡大佬牛福！
//Trick||Treat!

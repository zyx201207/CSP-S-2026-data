#include<bits/stdc++.h>
#define int long long
using namespace std;
struct aa{
	int num;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	int n,sum,x=1,y,ans=0;
	cin>>n;
	y=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	while(x<y){
		if(a[x].c==a[y].c){
			if(a[x].num>a[y].num){
				a[x].num-=a[y].num;
				y--;
			}else if(a[x].num<a[y].num){
				a[y].num-=a[x].num;
				x++;
			}else{
				x++,y--;
			}
		}else{
			if(a[x].num>a[y].num){
				ans+=a[y].num;
				a[x].num-=a[y].num;
				y--;
			}else if(a[x].num<a[y].num){
				ans+=a[x].num;
				a[y].num-=a[x].num;
				x++;
			}else{
				ans+=a[y].num;
				x++,y--;
			}
		}
	}
	cout<<ans;
	return 0;
} 

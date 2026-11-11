#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
struct node{
	int x;
	char y;
};
vector<node> a;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read();
	if(n==1){
		printf("0\n");
		return 0;
	}
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		int x=read();
		char y=getchar();
		getchar();
		a[i]={x,y};
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].y==a[r].y){
			if(a[l].x==a[r].x){
				a[l].x=0;
				a[r].x=0;
				l++;r--;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				a[r].x=0;
				r--;
			}
			else{
				a[r].x-=a[l].x;
				a[l].x=0;
				l++;
			}
		}
		else{
			if(a[l].x==a[r].x){
				ans+=a[l].x;
				a[l].x=0;
				a[r].x=0;
				l++;r--;
			}
			else if(a[l].x>a[r].x){
				ans+=a[r].x;
				a[l].x-=a[r].x;
				a[r].x=0;
				r--;
			}
			else{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				a[l].x=0;
				l++;
			}
		}
		//cout<<ans<<" "<<l<<" "<<r<<" "<<a[l].x<<" "<<a[r].x<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}

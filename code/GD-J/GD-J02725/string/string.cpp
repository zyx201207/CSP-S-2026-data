#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x;
	char c;
};
node num[200005];
node a[200005];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i].x;
		cin>>num[i].c;
	}
	int ans=0;
	int cnt=1;
	a[cnt].x=num[1].x;
	a[cnt].c=num[1].c;
	for(int i=2;i<=n;i++){
		if(num[i].c==a[cnt].c){
			a[cnt].x+=num[i].x;
		}else{
			a[++cnt].x=num[i].x;
			a[cnt].c=num[i].c;
		}
	}
	int l=1,r=cnt,no=a[1].x,nn=a[cnt].x;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(no<nn){
				ans+=no;
				nn-=no;
				l++;
				no=a[l].x;
			}else{
				ans+=nn;
				no-=nn;
				r--;
				nn=a[r].x;
			}
		}else{
			if(no<nn){
				nn-=no;
				l++;
				no=a[l].x;
			}else{
				no-=nn;
				r--;
				nn=a[r].x;
			}
		}
	}
	cout<<ans;
}

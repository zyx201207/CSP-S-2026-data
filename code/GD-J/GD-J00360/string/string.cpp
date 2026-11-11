#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,num;
struct node{
	int x;
	char c;
}a[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		num+=a[i].x;
	}	
	int l=1,r=n,n1=0,n2=0,ans=0;
	char c1='0',c2='0';
	while(l<=r){
		if(n1<n2){
			n1+=a[l].x;
			c1=a[l].c;
			l++;
		}
		else {
			n2+=a[r].x;
			c2=a[r].c;
			r--;
		}
		if(c1!=c2){
			if(n1<n2){
				ans+=n1;
				n2-=n1;
				n1=0;c1='0';
			}
			if(n1>n2){
				ans+=n2;
				n1-=n2;
				n2=0;c2='0';
			}
			if(n1==n2){
				ans+=n1;
				n1=0;n2=0;c1='0';c2='0';
			}
		}
		else{
			if(n1<n2){
				n2-=n1;
				n1=0;c1='0';
			}
			if(n1>n2){
				n1-=n2;
				n2=0;c2='0';
			}
			if(n1==n2){
				n1=0;n2=0;c1='0';c2='0';
			}
		}
	}
	cout<<ans;
	return 0;
}

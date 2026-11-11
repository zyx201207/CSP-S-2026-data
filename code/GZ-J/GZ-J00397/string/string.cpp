//GZ-J00397 张颜淏 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;

ll n,ans=0;
struct node{
	int x;
	char c;
}a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(l==r){
			break;
		}
		if(a[l].x<a[r].x){
			if(a[l].c!=a[r].c){
				ans+=a[l].x;
			}
			a[r].x-=a[l].x;
			a[l].x=0;
			l++;
		}else if(a[l].x==a[r].x){
			if(a[l].c!=a[r].c){
				ans+=a[l].x;
			}
			a[l].x=0;
			a[r].x=0;
			l++,r--;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[r].x;
			}
			a[l].x-=a[r].x;
			a[r].x=0;
			r--;
		}
	}
	cout<<ans;
	return 0;
}





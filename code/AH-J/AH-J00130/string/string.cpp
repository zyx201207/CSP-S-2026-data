#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct num{
	char c;
	LL x;
}a[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL cnt=0,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	LL l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].x>=a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else{
				a[r].x-=a[l].x;
				l++;
			}
		}else{
			if(a[l].x>=a[r].x){
				a[l].x-=a[r].x;
				cnt+=a[r].x;
				r--;
			}else{
				a[r].x-=a[l].x;
				cnt+=a[l].x;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

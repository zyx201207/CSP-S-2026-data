#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans;
struct mm{
	int x;
	char c;
};
mm a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	//cout<<"67";
	l=1;r=n;
	while(l<=r){
		if(a[l].c!=a[r].c){
			if(a[l].x>=a[r].x){
				ans+=a[r].x;
				a[l].x-=a[r].x;
				a[r].x=0;
			}else{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				a[l].x=0;
			}
		}else{
			if(a[l].x>=a[r].x){
				a[l].x-=a[r].x;
				a[r].x=0;
			}else{
				a[r].x-=a[l].x;
				a[l].x=0;
			}
		}
		if(a[l].x==0) l++;
		if(a[r].x==0) r--;
	}
	cout<<ans;
	return 0;
}

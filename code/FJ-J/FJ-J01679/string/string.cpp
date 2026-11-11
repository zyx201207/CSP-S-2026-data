#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
struct node{
	int a;
	char c;
	int l,r;
}q[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
		sum+=q[i].a;
	}
	q[1].l=1;
	q[1].r=q[1].a;
	for(int i=2;i<=n;i++){
		q[i].l=q[i-1].r+1;
		q[i].r=q[i].l+q[i].a-1;
	}
	int mid,mid1;
	if(sum%2==1){
		mid=(sum+1)/2;
	}
	else {
		mid=sum/2;
		mid1=sum/2+1;
	}
	int x=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(x>=mid) break;
		x+=q[i].a;
		int l1=q[i].l;
		int r1=q[i].r;
		int l2,r2;
		if(sum%2==1){
			l2=2*mid-l1;
			r2=2*mid-r1;
		}
		else{
			l2=mid-l1+mid+1;
			r2=mid-r1+mid+1;
		}
		int l3=sum-l2+1;
		int r3=sum-r2+1;
		int ss=0;
		int zs1=0,zs2=0;
		int cd1=0,cd2=0;
		for(int j=n;j>=1;j--){
			if(ss<l3&&ss+q[j].a>l3){
				zs1=j;
				cd1=q[j].a-(l3-ss);
			}
			if(ss+q[j].a==l3){
				zs1=j;
				cd1=q[j].a;
			}
			if(ss+q[j].a==r3){
				zs2=j;
				cd1=q[j].a;
			}
			if(ss+q[j].a>r3&&ss<r3){
				zs2=j;
				cd2=q[j].a-(r3-ss);
			}
			ss+=q[j].a;
		}
		if(zs1==zs2){
			if(q[zs1].c!=q[i].c) ans+=cd1;
			continue;
		}
		if(q[zs1].c!=q[i].c) ans+=cd1;
		if(q[zs2].c!=q[i].c) ans+=cd2;
		for(int j=zs2+1;j<zs1;j++){
			if(q[j].c!=q[i].c) {
				ans+=q[j].a;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

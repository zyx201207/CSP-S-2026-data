#include<bits/stdc++.h>
using namespace std;
int const N=2e5+7;
struct node{
	int num;
	char w;
}a[N],x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,mid,l_mid,r_mid;cin>>n;
	long long sum=0,k=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].w;
		sum+=a[i].num;
	}
	long long p=sum/2+sum%2;
	for(int i=1;i<=n;i++){
		k+=a[i].num;
		if(k>=p){
			mid=i;
			k-=a[i].num;
			r_mid=a[i].num+k-p;
			if(sum%2) l_mid=p-k-1;
			else l_mid=p-k;
			break;
		}
	}
	int l=1,r=n;
	x.num=a[l].num;x.w=a[l].w;
	y.num=a[r].num;y.w=a[r].w;
	while(1){
		while(!x.num&&l<=mid){
			l++;
			x.w=a[l].w;
			if(l==mid) x.num=l_mid; 
			else x.num=a[l].num;
		}
		while(!y.num&&r>=mid){
			r--;
			y.w=a[r].w;
			if(r==mid) y.num=r_mid; 
			else y.num=a[r].num;
		}
		if(l>mid||r<mid){
			cout<<ans;
			return 0;
		}
		int q=min(x.num,y.num);
		if(x.w!=y.w) ans+=q;
		x.num-=q;y.num-=q;
	}
	return 0;
}

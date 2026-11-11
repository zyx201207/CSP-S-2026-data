#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l;
	char id;
};
node g[200010],com[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long h=0;
	for(int i=1;i<=n;i++){
		cin>>g[i].l>>g[i].id;
		h+=g[i].l;
	}
	long long idx=1,mid=h/2,sum=0;
	node com[200010];
	while(sum<mid){
		if(sum+g[idx].l<=mid){
			sum+=g[idx].l;
			com[idx]=g[idx];
			idx++;
		}else{
			com[idx]=g[idx];
			com[idx].l=mid-sum;
			g[idx].l+=sum-mid-h%2;
			break;
		}
		if(sum==mid) g[idx].l-=h%2;
	}
	long long ans=0,i=1,j=n;
	while(j>=idx){
		long long mn=min(g[j].l,com[i].l);
		g[j].l-=mn,com[i].l-=mn;
		if(g[j].id!=com[i].id) ans+=mn;
		if(g[j].l==0) j--;
		if(com[i].l==0) i++;
	}
	cout<<ans;
}

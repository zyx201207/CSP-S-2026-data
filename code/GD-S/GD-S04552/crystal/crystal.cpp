#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m;
int a[N];
int ans;
int PT;
struct ac{
	int sum,tag;
}poi[N*4];
void build(int l,int r,int id){
	if(l==r){
		poi[id].sum=a[l];
		PT++;
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
	poi[id].sum=poi[id*2].sum+poi[id*2+1].sum;
	PT++;
	return ;
}
void push_down(int id,int l,int r){
	if(!poi[id].tag)
		return ;
	int L=id*2,R=id*2+1;
	int lazy=poi[id].tag;
	int mid=(l+r)/2;
	poi[id].tag=0;
	poi[L].sum+=(mid-l+1)*lazy;
	poi[R].sum+=(r-mid)*lazy;
	poi[L].tag+=lazy;
	poi[R].tag+=lazy;
	PT++;
	return ;
}
void Add(int l,int r,int id,int from,int to,int num){
	if(from<=l and to>=r){
		poi[id].sum+=(r-l+1)*num;
//		cout<<l<<" "<<r<<" "<<poi[id].sum<<" \n";
		poi[id].tag+=num;
		PT++;
		return ;
	}
	push_down(id,l,r);
	int mid=(l+r)/2;
	if(from<=mid){
		Add(l,mid,id*2,from,to,num);
	}
	if(to>mid){
		Add(mid+1,r,id*2+1,from,to,num);
	}
	poi[id].sum=poi[id*2].sum+poi[id*2+1].sum;
	PT++;
	return ;
}
int Get(int l,int r,int id,int from,int to){
	int ret=0;
	if(from<=l and to>=r){
		return poi[id].sum;
	}
	push_down(id,l,r);
	int mid=(l+r)/2;
	if(from<=mid){
		ret+=Get(l,mid,id*2,from,to);
	}
	if(to>mid){
		ret+=Get(mid+1,r,id*2+1,from,to);
	}
	poi[id].sum=poi[id*2].sum+poi[id*2+1].sum;
	PT++;
	return ret;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],PT++;
	sort(a+1,a+1+n);
	PT+=(n*log2(n));
	build(1,n,1);
	for(int i=n;i>=2;i--){
		if(a[i]==a[i+1])continue; 
		Add(1,n,1,1,i-1,a[i]*-1);
		int r=i-1;
		int j,k,p;
//		for(int o=1;o<=n;o++)
//			cout<<Get(1,n,1,o,o)<<" ";
//		cout<<"\n";
		int bef=i/2;
		PT++;
		for(j=i/2,k=i-1,p=1;;){
			PT++;
			if(Get(1,n,1,j,r)*-1<=m){
				int t=j;
				j=(j+p)/2;
				k=t;
			}else{
				int t=j;
				j=(j+k)/2;
				p=t;
			}
			if(bef==j)
				break;
			bef=j;
//			cout<<j<<" ";
		}
		while(true){
			if(j==1)break;
			if(Get(1,n,1,j-1,r)*-1<=m)
				j--;
			else
				break;
		}
			
		while(true){
			if(j==i-1)break;
			if(Get(1,n,1,j,r)*-1>m)
				j++;
			else break;
		}
//		cout<<j<<" ";
		ans=max(ans,i-j+1);
		Add(1,n,1,1,i-1,a[i]);
//		cout<<ans<<" ";
		PT++;
	}
	cout<<ans;
	return 0;
}

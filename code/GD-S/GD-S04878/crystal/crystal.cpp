#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
struct st{
	ll x;
	ll num;
}; 
ll a[N];
queue<st> q;
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	st sx;
	sx.num=0;
	sx.x=0;
	sort(a+1,a+n+1);
	a[n+1]=a[n]+1;
	ll sum=0,numx=0,dj=0,maxn=0,front=a[1];
	for(int i=1;i<=n;i++){
		numx++;
		if(a[i]!=a[i+1]){
			
			st sq;
			sq.x=a[i];
			sq.num=numx;
			q.push(sq);
			dj=dj+sum*(a[i]-front);
			front=a[i];
			//cout<<a[i]<<" "<<sum<<" "<<dj<<endl;
			if(dj>m){
				if(dj-(a[i]-sx.x)*sx.num<=m){
					if((dj-m)%(a[i]-sx.x)>0){
						ll numz=(dj-m)/(a[i]-sx.x)+1;
						sum-=numz;
						sx.num-=numz;
						dj=dj-numz*(a[i]-sx.x);
					}
					else{
						ll numz=(dj-m)/(a[i]-sx.x);
						sum-=numz;
						sx.num-=numz;
						dj=dj-numz*(a[i]-sx.x);
					}
				}
				else{
					sum-=sx.num;
					dj=dj-(a[i]-sx.x)*sx.num;
					sx.num=0;
					while(dj-(a[i]-sx.x)*sx.num>m&&!q.empty()){
					sum-=sx.num;
					dj=dj-(a[i]-sx.x)*sx.num;
					sx=q.front();
					q.pop();
					}
					if((dj-m)%(a[i]-sx.x)>0){
						ll numz=(dj-m)/(a[i]-sx.x)+1;
						sum-=numz;
						sx.num-=numz;
						dj=dj-numz*(a[i]-sx.x);
					}
					else{
						ll numz=(dj-m)/(a[i]-sx.x);
						sum-=numz;
						sx.num-=numz;
						dj=dj-numz*(a[i]-sx.x);
					}
				}
			}
			sum+=numx;
			numx=0;
			maxn=max(sum,maxn);
			
		}
	}

	cout<<maxn;
}

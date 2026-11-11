//string
#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct node{
	long long l,r;
	char c;
}a[200005];
vector<node > vz,vy;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long last=0;
	for(int i=1;i<=n;i++){
		long long s;
		char mq;
		cin>>s>>mq;
		a[i].c=mq;
		a[i].l=last+1LL;
		a[i].r=last+s;
		last+=s;
		sum+=s;
	}
	bool f=(sum%2==1);
	long long x=sum;
	sum/=2;
	for(int i=1;i<=n;i++){
		if(f){
			if(a[i].r<=sum+1){
				vz.push_back({a[i].l,min(a[i].r,sum),a[i].c});
			}else if(a[i].r>sum+1){
				if(a[i].l<=sum){
					vz.push_back({a[i].l,sum,a[i].c});
					vy.push_back({sum+2,a[i].r,a[i].c});
				}else{
					vy.push_back({max(a[i].l,sum+2),a[i].r,a[i].c});
				}
			}
		}else{
			if(a[i].r<=sum){
				vz.push_back({a[i].l,a[i].r,a[i].c});
			}else{
				if(a[i].l<=sum){
					vz.push_back({a[i].l,sum,a[i].c});
					vy.push_back({sum+1,a[i].r,a[i].c});
				}else{
					vy.push_back({a[i].l,a[i].r,a[i].c});
				}
			}
		}
	}
	for(int i=(int)vy.size()-1;i>=0;i--){
		vy[i].r=x-vy[i].r+1;
		vy[i].l=x-vy[i].l+1;
	}
	long long z=0,y=vy.size()-1,ans=0;
	while(z<vz.size()&&y>=0){
		if(vz[z].c!=vy[z].c){
			if(min(vy[y].l,vz[z].r)>=max(vy[y].r,vz[z].l))
				ans+=min(vy[y].l,vz[z].r)-max(vy[y].r,vz[z].l)+1;
		}
		if(vy[y].l>vz[z].r){
			z++;
		}else if(vy[y].l<vz[z].r){
			y--;
		}else{
			z++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

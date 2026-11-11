#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500001;
int n,m,a[N],b[N],allans=INT_MIN;
struct c{
	int local;
	int num;
};
c update(c now,c maybe){
	if(now.num<maybe.num){
		now=maybe;
	}
	if(now.local<maybe.local&&now.num==maybe.num){
		now=maybe;
	}
}
signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
//ios::sync_with_stdio(false);
//cin.tie(0);

cin>>n>>m>>a[0];
for(int i=1;i<n;i++){
	cin>>a[i];
	b[i]=a[i]-a[i-1];
}
int now=m;
int l=0,r=1;
c maxi={0,a[0]};

while(1){
	for(int i=l;i<r;i++){
		maxi=update(maxi,{i,a[i]});
	}
	while(1){//r++
		if(r==n-1) break;
		if(a[r+1]>maxi.num&&(r-l)*(maxi.num-a[r])){
			now-=(r-l)*(maxi.num-a[r]);
			r++;
			maxi={r,a[r]};
		}else if(a[r+1]<=maxi.num&&maxi.num-a[r+1]<now){
			now-=maxi.num-a[r+1];
			r++;
		}else break;
	}	
	//cout<<"\n当前区间："<<l<<'~'<<r;
	allans=max(allans,r-l);
	if(l>r||r>=n-1) break;
	//l++
	if(l==maxi.local){
		int tmp=maxi.num;
		maxi={l+1,a[l+1]};
		for(int i=l+1;i<r;i++){
			maxi=update(maxi,{i,a[i]});
		}
		now+=(tmp-maxi.num*(r-l+1));
		l++;
	}else{
		now+=maxi.num-a[l];
		l++;
	}


}
cout<<allans+1;
}


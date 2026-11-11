#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int LOG=25;

int t,n;
int L[2000005];
int LA[2000005][LOG];
int R[2000005];
int RA[2000005][LOG];
ll dis;
ll lsum[200005];
ll rsum[200005];
ll P[2000005];

void File(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}

void Calculate(){
	int bh=1;
	for(int l=1;l<=n;l++){
		while(bh<=n&&P[bh]-P[l]<=dis){
			bh++;
		}
		bh--;
		R[l]=bh;
	}
	bh=n;
	for(int r=n;r;r--){
		while(bh&&P[r]-P[bh]<=dis){
			bh--;
		}
		bh++;
		L[r]=bh;
	}
}

inline void ST_Init(){
	for(int i=1;i<=n;i++){
		RA[i][0]=R[i];
	}
	for(int k=1;k<LOG;k++){
		for(int i=1;i<=n;i++){
			RA[i][k]=RA[RA[i][k-1]][k-1];
		}
	}
	for(int i=n;i>=1;i--){
		RA[i][0]=R[i];
	}
	for(int k=1;k<LOG;k++){
		for(int i=n;i>=1;i--){
			RA[i][k]=RA[RA[i][k-1]][k-1];
		}
	}
}

int LGet(int bh,int k){
	for(int i=LOG;i>=0;i--){
		if(k&(1<<i)){
			bh=LA[bh][i];
		}
	}
	return bh;
}

bool LCheck(int mid,int x,int y){
	if(!mid){
		return 1;
	}
	return LGet(x,mid-1)>LGet(y,mid);
}

int LSearch(int x,int y){
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(LCheck(mid,x,y)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}

int RGet(int bh,int k){
	for(int i=LOG;i>=0;i--){
		if(k&(1<<i)){
			bh=RA[bh][i];
		}
	}
	return bh;
}

bool RCheck(int mid,int x,int y){
	if(!mid){
		return 1;
	}
	return RGet(x,mid)>RGet(y,mid-1);
}

int RSearch(int x,int y){
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(RCheck(mid,x,y)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}

int main(){
	File();
	cin>>t>>t;
	while(t--){
		cin>>n>>dis;
		for(int i=1;i<=n;i++){
			cin>>P[i];
		}
		Calculate();
		ST_Init();
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(R[i]<=i+1){
				continue;
			}
			int bh=R[i]-1;
			if(R[bh]<=R[i]){
				continue;
			}
			ans+=LSearch(bh,R[i])*RSearch(bh,R[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
WA
*/

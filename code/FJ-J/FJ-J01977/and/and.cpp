#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int mya[N][40];
int can_use[N];
int max_len=0;
int ans=0;
void change(int myid,int myx){
	int cnt=0;
	if(myx==0){
		return;
	}
	while(myx!=0){
		cnt++;
		if(myx&1){
			mya[myid][cnt]=1;
		}else{
			mya[myid][cnt]=0;
		}
	    myx=myx>>1;
	}
	max_len=max(max_len,cnt);
	return;
}
int power(int myx,int myy){
	int base=myx;
	int res=1;
	while(myy!=0){
		if(myy&1)  res=res*base;
		base=base*base;
		myy=myy>>1;
	}
	return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		can_use[i]=1;
		change(i,a[i]);
	}
    for(int i=max_len;i>=1;i--){
    	int my_cnt=0;
    	for(int j=1;j<=n;j++){
    		if(mya[j][i]==1&&can_use[j]!=-1){
    			my_cnt++;
			}	
		}
		if(my_cnt>=m){
			ans+=power(2,i-1);
			for(int j=1;j<=n;j++){
				if(mya[j][i]==0){
					can_use[j]=-1;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

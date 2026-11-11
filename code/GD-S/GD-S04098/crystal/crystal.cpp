#include<bits/stdc++.h>
using namespace std;

//喜极而泣 
//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
// ----------------------------------------- //
//      *     ##########        *                 //
// -----|-----------------------|----------- //
//        |                            \   |                //
//      |||||||||||||\    |||||||||||||||||||\\                  //
//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh

long long a[500010],f[500010];
long long n,m,ans=0,cur=-1;
bool ck(long long w,long long xx){//ck
    long long uu=a[xx]*(xx-w)-f[xx-1]+f[w-1];
	return uu<=m;                                                                                                                                                                                                                                                                                    
}
void check(long long x){//右 
    long long l=1,r=x;
	while(l<=r){
		long long mid=l+r>>1;
		if(ck(mid,x)){
			cur=max(cur,x-mid+1);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}    
	return;                                                                                                                                                                                                                                                                              
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	for(int i=1;i<=n;i++){
		check(i);
		ans=max(ans,cur);
		cur=-1;
//		long long uu=a[x]*(x-1)-f[x-1];
//		if(uu<=m){
//			ans=max(ans,x);
//			l=x+1;
//		}
//		else{
//			r=x-1;
//		} 
	}
	cout<<ans;
	return 0;
} 
//5 5
//1 2 4 8 9

//5 8
//-3 -1 2 2 7
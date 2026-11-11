#include<iostream>
#define N 200010
using namespace std;
int n,m,ans=(1<<30)-1;
int oldc=0,newc=1,r[2][N];
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[0][i];
	}
	for(int i=29;i>=0;i--){
		int l=0;
		for(int j=1;j<=n;j++){
			if((r[oldc][j]>>i)&1){
				r[newc][++l]=r[oldc][j];
			}
		}
		if(l>=m){
			n=l;
			swap(newc,oldc);
		}
	}
	swap(newc,oldc);
	for(int i=1;i<=n;i++){
		ans&=r[newc][i];
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define rt return
#define ffor(a,b,c,d) for(int (a)=(b);(a)<(c);(a)+=(d))
using namespace std;
const int N=2e5+10;
int ax[N],n,m,ans;
bool fcmp(int a,int b){
	int aa=0,bb=0;
	while(a){
		if(a&1){
			aa++;
		}
		a=a>>1;
	}
	while(b){
		if(b&1){
			bb++;
		}
		b=b>>1;
	}
	rt aa>bb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ffor(i,0,n,1){
		cin>>ax[i];
	}
	sort(ax,ax+n,fcmp);
	ans=ax[0];
	ffor(i,1,m,1){
		ans&=ax[i];
	}
	cout<<ans;
	rt 0;
}
//code by Rufory
//FJ-J01100

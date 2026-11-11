#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],cha[N],ans,su[N],sh,xu;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	for(int i=n;i>=1;i--){
		su[i]+=su[i+1]+cha[i+1];//su[i]-su[j] = i->j »¨·Ñ 
	}
	ll l=1,r_num,r=1;
	ll num=0;

	sh=m;
	while(r<=n &&l<=r){
		
		xu=(su[r]-su[r+1])*(r-l+1);
		while(sh>=xu && r+1<=n){
			r++;
			ans=max(ans,r-l+1);
			sh-=xu;
			xu=(su[r]-su[r+1])*(r-l+1);
		}
		
		sh+=(su[l]-su[r]);
		l++;
		xu=(su[r]-su[r+1])*(r-l+1);
		if(sh>=xu && r+1<=n && l<=r){
			r++; 
			ans=max(ans,r-l+1);
			sh-=xu;
			
		}
	}
	cout<<ans;
//	
//5 8
//-3 -1 2 2 7

//5 5
//1 2 4 8 9
	return 0;
}

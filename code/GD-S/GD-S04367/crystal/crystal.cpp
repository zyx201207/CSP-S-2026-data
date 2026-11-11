#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N];
int n;ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
//	cout<<"cin finish\n"<<n<<' '<<m<<'\n';
	sort(a+1,a+n+1);
	int ans=1;//it cun the number of the xiaohuozi
	int l=1;
	ll cnt=0;//it cun all members turn to a[r-1] need pay how much
	for(int r=2;r<=n;r++){
		//------------------------------------
//		cout<<"now self at:"<<r<<'\n';
		//------------------------------------
		//push into the queue
		cnt+=ll(r-l)*1LL*(a[r]-a[r-1]);
//		cout<<"cnt="<<cnt<<'\n';
		if(cnt>m){//invalid
			//cout<<"because "<<cnt<<'>'<<'m'<<'\n';
			//gui some member out of the queue
			while(l<=r&&cnt>m){
				//cout<<"get out member:"<<l;
				cnt-=(a[r]-a[l++]);
//				cout<<"  cnt change to:"<<cnt<<'\n';
			}
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 

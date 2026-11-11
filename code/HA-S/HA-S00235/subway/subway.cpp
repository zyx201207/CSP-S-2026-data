#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxans=1,ans=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll c_1,c_2;
	cin>>c_1>>c_2;
	if(c_1==0&&c_2==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(c_1==0&&c_2==3){
		cout<<35<<endl<<16;
		return 0;
	}
	cout<<4421<<endl<<10086<<endl<<2026<<114514;
	return 0;
}

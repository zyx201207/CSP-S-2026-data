#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;

int ans;
struct f{
	int a;
	char c;
}o[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	bool b=true;
	for(int i=1;i<=n;++i){
		cin>> o[i].a >> o[i].c;
		if(i>1 && o[i-1].c!=o[i].c) b=false;
	}
	if(b){
		cout<<"0";
		return 0;
	}
	
	int lp=1 , rp=n;
	while(lp<rp){
		if(o[lp].c!=o[rp].c){
			ans+=o[lp].a;
			lp++,rp--;
		}
	}
	
	cout<<ans;
	return 0;
}


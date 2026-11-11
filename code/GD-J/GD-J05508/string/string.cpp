#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+7;
struct Node{ int x;char c; }a[N];
int n,l;
ll sum,ans,s;
vector<Node> v1,v2;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c,sum+=a[i].x;
	for(int i=1;i<=n;i++){
		if(s+a[i].x>=(sum/2)){
			v1.push_back({sum/2-s,a[i].c});
			break;
		}else v1.push_back({a[i].x,a[i].c}),s+=a[i].x;
	}s=0;
	for(int i=n;i>=1;i--){
		if(s+a[i].x>(sum/2)){
			v2.push_back({sum/2-s,a[i].c});
			break;
		}else v2.push_back({a[i].x,a[i].c}),s+=a[i].x;
	}
	int x1=v1[0].x,x2=v2[0].x;
	char c1=v1[0].c,c2=v2[0].c;
	for(int i=0,j=0;i<v1.size()&&j<v2.size();){
		if(x1==x2){
			ans+=(c1==c2)?0:x1;
			i++,j++;
			x1=v1[i].x,x2=v2[j].x;
			c1=v1[i].c,c2=v2[j].c;
		}else if(x1>x2){
			ans+=(c1==c2)?0:x2;
			x1-=x2;j++;
			x2=v2[j].x;c2=v2[j].c;
		}else if(x2>x1){
			ans+=(c1==c2)?0:x1;
			x2-=x1;i++;
			x1=v1[i].x;c1=v1[i].c;				
		}
	}
	cout<<ans<<'\n';
	return 0;
}

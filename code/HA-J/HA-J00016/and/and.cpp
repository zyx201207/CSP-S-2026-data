#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct node{
	int res;
	long long x;
//	bool operator > (const node& other) const{
//		if(res>other.res){
//			return res>other.res;
//		}else{
//			return x>other.x;
//		}
//	}
}a[N];
int n,m;
bool temp(node &x,node &y){
	if(x.res>y.res){
		return x.res>y.res;
	}else{
		return x.x>y.x;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
	}
//	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=n;i++){
		long long tmp=a[i].x;
		while(tmp>0){
			if(tmp&1){
				a[i].res++;
			}
			tmp>>=1;
		}
//		cout<<a[i].res<<'\n';
	}
//	cout<<temp(a[1],a[2]);
	sort(a+1,a+n+1,temp);
	long long ans=a[1].x;
	for(int i=1;i<=m;i++){
//		cout<<a[i].x<< ' ';
		ans&=a[i].x;
	}
	cout<<ans;
	return 0;
}

#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,k;
	long long x,s=0;
	cin>>c>>n>>m>>d>>q;
	while(m--) cin>>x,s+=x;
	while(n--){
		cin>>k;
		for(int i=1;i<=2*k;i++) cin>>x;
	}
	while(q--){
		cin>>x>>x;
		cout<<s<<endl;
	}
	return 0;
}

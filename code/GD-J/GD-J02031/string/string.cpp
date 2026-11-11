#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,l,ans;
struct point{
	ull as;
	string cs; 
}p[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	ull a;
	string c;
	for(ull i=0;i<n;i++){
		cin>>a>>c;
		p[i].as = a;
		p[i].cs = c;
		l+=a;
	}
	ull mid=0;
	ull lp=0;
	for(ull i=0;i<n;i++){
		lp+=p[i].as ;
		if(lp>=l/2+1){
			mid=i;
			if(l&1){
				p[i].as --;
			}
			break;
		}
	}
	for(ull i=0;i<mid;i++){
		for(ull j=mid;j<n;j++){
			if(p[i].cs != p[j].cs ){
				ans+=min(p[i].as , p[j].as );
				p[j].cs =p[i].cs ;
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct s{
	ll x;
	char y;
};
ll i,n,a,x=0;
deque<s>v;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>c;
		v.push_back(s{a,c});
	}
	while(1){
		if(v[0].y!=v[n-1].y){
			x+=min(v[0].x,v[n-1].x);
		}
		if(v[0].x==v[n-1].x){
			v.pop_front();
			v.pop_back();
			n-=2;
		}else if(v[0].x<v[n-1].x){
			v[n-1].x-=v[0].x;
			v.pop_front();
			n--;
		}else{
			v[0].x-=v[n-1].x;
			v.pop_back();
			n--;
		}
		if(n<=1){
			cout<<x;
			return 0;
		}
	}
	return 0;
}

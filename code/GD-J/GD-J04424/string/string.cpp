#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	ll k;
	string s;
};
deque<st> a;
ll sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//reserve
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s1;
		ll k1;
		cin>>k1>>s1; 
		a.push_back({k1,s1});
	}
	ll len=a.size();
	st x=a.front();
	st y=a.back();
//	cout<<x.k<<" "<<x.s<<endl;
//	cout<<y.k<<" "<<y.s;
	while(!a.empty()){
		if(a.size()==1){
			break;
		}
		st x=a.front();
		st y=a.back();
		if(x.k>y.k){
			a.pop_back();
			a.front().k-=y.k;
		}
		else if(x.k<y.k){
			a.pop_front();
			a.back().k-=x.k;
		}
		else {
			a.pop_back();
			a.pop_front();
		}
		if(x.s!=y.s) sum+=min(x.k,y.k);
	}
	cout<<sum;
	return 0;
}
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b


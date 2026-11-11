#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ans,s;
char c,f,b;
deque<pair<long long,char> > d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		d.push_back({a,c});
	}
	while(d.size()>=2){
		s=min(d.front().first,d.back().first);
		f=d.front().second;
		b=d.back().second;
		if(f!=b){
			ans+=s;
		}
		d.front().first-=s;
		d.back().first-=s;
		if(!d.front().first){
			d.pop_front();
		}
		if(!d.back().first){
			d.pop_back();
		}
	}
	cout<<ans;
	return 0;
}

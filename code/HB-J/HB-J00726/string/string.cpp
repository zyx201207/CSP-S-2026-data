#include<bits/stdc++.h>
#define endl "\n"
#define ull unsigned long long
using namespace std;
int n;
ull ans;
vector<pair<ull,char>> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	v.push_back({0,'A'});
	cin>>n;
	for(int i=1;i<=n;i++){
		ull a;
		char c;
		cin>>a>>c;
		if(c==v[v.size()-1].second) v[v.size()-1].first+=a;
		else v.push_back({a,c});
	}
	n=v.size()-1;
	int mid=ceil(n*1.0/2);
	//cout<<"*n:"<<n<<endl;
	//cout<<"*mid:"<<mid<<endl;
	for(int i=1;i<=mid;i++){
		int j=2*mid-i;
		if(!(n%2)&&i==mid) j++;
		if(i!=mid){
			ull z=v[i].first-v[j].first;
			if(v[i].first>v[j].first){
				v[i+1].first+=z;
				v[i].first=v[j].first;
				ans+=z;
			}
			else if(v[i].first>v[j].first){
				v[j-1].first+=z;
				v[j].first=v[i].first;
				ans+=z;
			}
		}
		else if(!(n%2)){
			ull z=v[i].first-v[j].first;
			if(z%2==0) ans+=z/2;
			else ans+=(z+1)/2;
		}
		if(v[i].second!=v[j].second){
			ans+=v[i].first;
		} 
		//cout<<"*i:"<<i<<endl;
		//cout<<"*j:"<<j<<endl;
	}
	cout<<ans<<endl;
	//for(auto e:v){
	//	cout<<"*"<<e.first<<"*"<<"*"<<e.second<<"*"<<endl;
	//}
	return 0;
}

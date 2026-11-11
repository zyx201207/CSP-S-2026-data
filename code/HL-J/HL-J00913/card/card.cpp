#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+9;
int n,m,book[MAXN];
vector<int>vec;
vector<int>vec2;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a,vec.push_back(a);
	}
	for(int i=0;i<n;i++){
		vec2.clear();
		for(int j=i;j<n;j++){
			if(vec2.size()){
				auto p=lower_bound(vec2.begin(),vec2.end(),vec[j]);
				if(*p==vec[j]) vec2.erase(p,vec2.end());
			}
			vec2.push_back(vec[j]);
		}
		for(int v:vec2) book[v]++;
	}
	for(int i=1;i<=m;i++) cout<<book[i]<<' ';
	return 0;  
}
//10 3 3 1 2 1 3 2 3 1 2 1
//4 3 1 2 1 3
//21 2 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
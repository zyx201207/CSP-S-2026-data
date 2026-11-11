#include <bits/stdc++.h>
using namespace std;
const int N=200000+5;
typedef pair<int,char> PII;
int n;
long long ans=0;
PII v[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>v[x].first>>v[x].second;
	}
	for(int l=1,r=n;l<r;){
		int sum;
		bool t=1;
		if(v[l].second==v[r].second)t=0;
		if(v[l].first>v[r].first){
			sum=v[r].first;
			v[l].first-=v[r].first;
			r--;
		}else if(v[l].first<v[r].first){
			sum=v[l].first;
			v[r].first-=v[l].first;
			l++;
		}else if(v[l].first==v[r].first){
			sum=v[l].first;
			l++;r--;
		}
		if(t)ans+=sum;
	}
	cout<<ans;
	return 0;
}

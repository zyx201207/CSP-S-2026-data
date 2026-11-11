#include <bits/stdc++.h>
using namespace std;
long long ans,m,mid;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<pair<long long,char>> s;
	int n,nn=0,now=0; cin>>n;
	for (int i=0;i<n;i++){
		pair<int,char> x; cin>>x.first>>x.second;
		if (i>0 && (s[now-1].second==x.second)) {s[now-1].first+=x.first;m+=x.first;}
		else {s.push_back(x);now++;m+=x.first;nn++;}
	}
	mid=m/2; long long a=0,l=0,y=0,r=nn-1;
	while (y<mid){
		if (s[l].first==0) l++;
		if (s[r].first==0) r--;
		a=min(min(s[l].first,s[r].first),mid-y);
		if (s[l].second!=s[r].second) ans+=a;
		s[l].first-=a; s[r].first-=a;
		y+=a;
	}
	cout<<ans;
	return 0;
}

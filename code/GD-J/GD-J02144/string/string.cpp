#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
pair<int,char> a[maxn];
int n;
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
	int len=0;
	for(int i=1;i<=n;i++) len+=a[i].first;
	if(len%2==1){
		int idx=0;
		for(int i=1;i<=n;i++){
			idx+=a[i].first;
			if(idx>=len/2+1){
				a[i].first--;
				len--;
				break;
			}
		}
	}
	vector<pair<int,char>> b,c;
	int i=1,idx=0;
	for(;i<=n;i++){
		idx+=a[i].first;
		if(idx<len/2) b.push_back({a[i].first,a[i].second});
		else if(idx==len/2){
			b.push_back({a[i].first,a[i].second});
			break;
		}else if(idx>len/2){
			b.push_back({a[i].first-(idx-len/2),a[i].second});
			break;
		}
	}
	i=n,idx=0;
	for(;i>=1;i--){
		idx+=a[i].first;
		if(idx<len/2) c.push_back({a[i].first,a[i].second});
		else if(idx==len/2){
			c.push_back({a[i].first,a[i].second});
			break;
		}else if(idx>len/2){
			c.push_back({a[i].first-(idx-len/2),a[i].second});
			break;
		}
	}
	int ans=0;
	while(!b.empty()&&!c.empty()){
		int i=b.size()-1,j=c.size()-1;
		if(b[i].first<c[j].first){
			c[j].first-=b[i].first;
			if(b[i].second!=c[j].second) ans+=b[i].first;
			b.pop_back();
		}else if(b[i].first>c[j].first){
			b[i].first-=c[j].first;
			if(b[i].second!=c[j].second) ans+=c[j].first;
			c.pop_back();
		}else{
			if(b[i].second!=c[j].second) ans+=c[j].first;
			b.pop_back();
			c.pop_back();
		}
	}
	cout << ans << endl;
	return 0;
}

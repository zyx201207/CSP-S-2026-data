#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int M=31;
typedef long long ll;
#define endl '\n'

ll n,m,a[N],d[N][M];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		int x=a[i],cnt=0;
		while (x){
			d[i][cnt]=(x&1);
			cnt++;
			x/=2; 
		}
	}
	vector<int> c;
	for (int j=30;j>=0;j--){
		c.clear();
		for (int i=1;i<=n;i++)
			if (d[i][j])
				c.push_back(i);
		if (c.size()>=m)
			break;
	}
	if (c.size()<m){
		cout << "0\n";
		return 0;
	}
	for (int j=30;j>=0;j--){
		vector<int> now;
		for (auto y:c)
			if (d[y][j])
				now.push_back(y);
		if (now.size()>=m)
			c=now;
	}
	ll ans=0;
	for (int i=0;i<=31;i++)
		ans*=2,ans+=1;
	int i=1;
	for (auto y:c){
		ans&=a[y];
		i++;
		if (i>m)
			break;
	}
	cout << ans << '\n';
	return 0;
}


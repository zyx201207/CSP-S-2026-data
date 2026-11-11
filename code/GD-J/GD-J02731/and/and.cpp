#include <bits/stdc++.h>
using namespace std;
int a[200010][50];
vector <int> b[50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		long long k;
		cin >> k;
		int j=1;
		while(k>0){
			if (k%2){
				a[i][j]=1;
				b[j].push_back(i);
			}
			k/=2;
			j++;
		}
	}
	int c=1,d=32;
	while (c&&d>0){
		d--;
		if (b[d].size()>=m)
			c=0;
	}
	if (d<=0){
		cout << 0;
		return 0;
	}
	long long ans,q=1;
	for (int i=1;i<d;i++)
		q*=2;
	ans=q;
	queue <int> e;
	for (int i=0;i<b[d].size();i++)
		e.push(b[d][i]);
	for (int i=d-1;i>0;i--){
		q/=2;
		int j=b[d].size(),k=e.size(),p=0;
		if (j<m)
			continue;
		for (int o=0;o<k;o++){
			if (a[e.front()][i])
				p++;
			e.push(e.front());
			e.pop();
		}
		if (p>=m){
			ans+=q;
			for (int o=0;o<k;o++){
				if (a[e.front()][i])
					e.push(e.front());
				e.pop(); 
			}
		}
	}
	cout << ans;
	
	return 0;
}

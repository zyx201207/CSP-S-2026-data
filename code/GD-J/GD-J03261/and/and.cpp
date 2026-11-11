#include <bits/stdc++.h>
using namespace std;
int countbit(int x){
	int cnt=0;
	while (x){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	bool flag=true;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]!=i){
			flag=false;
		}
	}
	sort(a.begin(),a.end(),[&](int a,int b){
		if (countbit(a)==countbit(b)) return a>b;
		return countbit(a)>countbit(b);	
	});
	int ans=a[0];
	for (int i=1;i<m;i++) ans&=a[i];
	cout<<ans<<"\n";
	return 0;
}

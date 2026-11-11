#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
vector<int> c;
int n,m;

int solve(int v,int m,int n){
	int ans = 1;
	int want = c[v];
	for(int i = v+1;i<n;i++){
		m -= want - c[i];
		if(m<0) break;
		ans++;
	}
//	cout<<"µ÷ÓÃ"<<ans<<endl;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	c.resize(n,0);
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	sort(c.begin(),c.end(),cmp);
	int want = c[0];
	int lowest = c[n-1];
	int t = 0;
	while(want-lowest>m){
		t++;
		want = c[t];
	}
//	cout<<want<<endl<<t<<endl;
	int ans = 0;
	for(int i = t;i+ans<n-1;i++){
//		cout<<i<<' ';
		ans = solve(i,m,n);	
	}
//	cout<<endl;
	cout<<ans;
	return 0;
}

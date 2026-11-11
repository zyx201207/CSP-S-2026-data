#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;//测试点编号与测试数据组数
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k,a[100005],b[100005],c[100005],de=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i]>>b[i];
			c[a[i]]++;
			c[b[i]]++;
		}
		de=c[1];
		for(int i=2;i<n;i++){
			de=max(c[i],de);
		}
		cout<<(de-1)/k+1<<endl;
	}
	return 0;
}


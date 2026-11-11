#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[31],h[200005],cnt=0;
long long num=0;
priority_queue<long long> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	f[0]=1;
	for (int i=1;i<=30;i++){
		f[i]=f[i-1]*2;
	}
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for (int i=30;i>=1;i--){
		long long top=q.size();
		cnt=0;
		for (int j=1;j<=top;j++){
			if (q.top()/f[i-1]==1){
				cnt++;
				h[cnt]=q.top()%f[i-1];
				q.pop();
			}
		}
		if (cnt>=m){
			while (!q.empty()) q.pop();
			num+=f[i-1];
		}
		for (int j=1;j<=cnt;j++){
			q.push(h[j]);
		}
	}
	cout<<num;
	return 0;
}

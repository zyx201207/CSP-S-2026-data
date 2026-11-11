#include<bits/stdc++.h>
using namespace std;

int n,m;
priority_queue<int>a;
int b[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ans=0,t=0,k;
	for(int i=1;i<=n;i++){
		cin>>k;
		a.push(k);
	}
	for(int i=1;i<=n;i++){
		b[i]=a.top();
		a.pop();
		if(i<m)continue;
		t=b[i-m+1];
		for(int j=i-m+1;j<=i;j++){
			t=t&b[j];
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}

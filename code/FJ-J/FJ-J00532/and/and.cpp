#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long m=0,n;
int fff(int x,int w){
	if(w==m){
		return x;
	}
	int q=-1;
	for(int i=x+1;i<=n;i++){
		q=max(q,q&fff(a[i],w+1));
	}
	return q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int qm=0,zh=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qm=max(qm,a[i]);
	}
	if(m==1){
		cout<<qm;
		return 0;
	}
	if(m==n){
		zh=a[1];
		for(int i=2;i<=n;i++){
			zh=zh&a[i];
		}
		cout<<zh;
		return 0;
	}
	cout<<fff(1,1);
	return 0;
}

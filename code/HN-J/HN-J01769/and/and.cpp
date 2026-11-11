#include<bits/stdc++.h>
using namespace std;
int an[2000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,p=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
	}
	if(m==1){
		sort(an+1,an+1+n);
		cout<<an[n];
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			p&=an[i];
		}
		cout<<p;
		return 0;
	}
	if(m==2){
		int mx=-10001;
		for(int i=1;i<=n-1;i++){
			int mx=max((an[i]&an[i+1]),mx);
			if(i==n-1) cout<<mx;
		}
	}
	return 0;
}

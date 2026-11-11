#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,m;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxx=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}else if(m==n){
		int k=0;
		for(int i=1;i<=n;i++){
			k=k&a[i];
		}
		maxx=k;
	}
	cout<<maxx<<endl;
	return 0;
}

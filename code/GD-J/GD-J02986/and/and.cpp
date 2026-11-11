#include<bits/stdc++.h>
using namespace std;
int maxa=0,a[100005];
char c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxa<a[i]){
			maxa=a[i];
		}
	}
	cout<<maxa;
	return 0;
	
}

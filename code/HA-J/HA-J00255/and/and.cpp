#include <bits/stdc++.h>
using namespace std;
long long n,m,c;
long long w[200005];
//bool cmp(int a,int b){
//	return a>b;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+n+1);
	for(int i=1;i>=n;i++){
		c=w[i]&&w[i+1];
	}
	cout<<c<<endl;
	return 0;
}

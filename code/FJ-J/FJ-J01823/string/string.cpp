#include<bits/stdc++.h>
using namespace std;
long long n;
string x;
struct dp{
	int m;
	char j;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].j;
		while(a[i].m){
			x[ans]=a[i].j;
			ans++;
			a[i].m--;
		}
	}
	int cnt=0;
	for(int i=0;i<ans/2;i++){
		if(x[i]!=x[ans-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int cnt=0;
typedef long long ll;
const int N=1e5+10;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<=n;k++){
				cin>>a[k];
			}
			while(n>0&&a[j]<a[i]){
				m--;
				a[j]++;
			}
		}
	}cout<<cnt;
	return 0;
}

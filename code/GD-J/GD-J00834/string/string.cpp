#include<bits/stdc++.h>
const int N=2e5+5;
#define int long long
using namespace std;
int a[N];
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n,k=1,m=n,cnt=0;
	while(i<j){
		if(a[i]==0){
			k++;
			i++;
		}
		if(a[j]==0){
			m--;
			j--;
		}
		if(i>=j)break;
		if(b[k]!=b[m]){
			cnt++;
		}
		a[i]--;
		a[j]--;
	}
	cout<<cnt;
	return 0;
}

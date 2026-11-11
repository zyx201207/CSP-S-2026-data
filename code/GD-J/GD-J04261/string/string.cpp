#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100005],cnt = 0,m = 0;
char c[100];
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		//m += a[i];
		//s += a[i]*c[i];
	}
	if(n == 1){
		cout<<0;
	}
	for(int i = 1;i <= ceil(n/2);i++){
		for(int j = n+1-i;j <= n+1-i;j++){
			if(c[j] != c[i]){
				cnt += max(a[j],a[i]);
			}
			if(j == i && a[j+1] != a[i-1]){
				cnt += max(a[j+1],a[i-1])-min(a[j+1],a[i-1]);
			}
		}
	}
	cout<<cnt;
}

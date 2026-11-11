#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int a[N];
int b[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j]) continue;
			if(a[j]&(1<<i)){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(b[j]) continue;
				if(!(a[j]&(1<<i))){
					b[j]=1;
				}
			}
			ans|=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}

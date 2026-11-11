#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[10001];
	cin>>a[n];
	int ans=0;
	for(int i=0;i<=n;i++){
		int k=a[i];//下一个数的 
		int b=a[i-1];//这个数的 
		for(int j=0;j<=i;j++){
			if(a[k]>=a[b]){
				m--;
				b++;
				while(k=b){
					ans++;
				}
			}else{
				break;
			} 
		}
	}
	cout<<ans;
	return 0;
}

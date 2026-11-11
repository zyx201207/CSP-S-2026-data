#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+2;
long long n,m,a[N],ans[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		sort(ans+1,ans+1+n);
		cout<<ans[n];
	}
	else if(a[1]+1==a[2]&&a[2]+1==a[3]){
		int b=0,j=1;
		while(1){
			if(m-j>=0){
				m-=j;
				j++;
				b++;
			}
			if(m-j<0) break;
		}
		cout<<b+1;
	}
	else if(a[2]-a[1]==a[3]-a[2]){
		int b=0,j=a[4]-a[3];
		while(1){
			if(m-j>=0){
				m-=j;
				j+=j;
				b++;
			}
			if(m-j<0) break;
		}
		cout<<b+1;
	}
	return 0;
} 

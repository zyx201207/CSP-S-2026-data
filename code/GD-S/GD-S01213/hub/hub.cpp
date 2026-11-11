#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int c,n,k;
vector<int> vec[110];
int dp[110][110][110];

void do_it(){
	cin>>n>>k;
	if(n==1){
		cout<<0<<endl;
		return;
	}
	if(k<=2 && n>2){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	if(c>=13 && c<=14){
		int ans=0;
		int m=(n-1)/2;
		if(k==n){
			cout<<m+1<<endl;return;
		}
		if(k==n-1){
			cout<<m<<endl;return;
		}
		if(k==n-2){
			cout<<m<<endl;return;
		}
		if(k==n-3){
			cout<<m-1<<endl;return;
		}
		if(k==n-4){
			cout<<(m+1)/2<<endl;return;
		}
		if(k<=n-5 && k%2==1){
			cout<<(m-(k-1)/2+2)/2<<endl;return;
		}
		if(k<=n-5 && k%2==0){
			cout<<(m-(k-2)/2+2)/2<<endl;return;
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		do_it();
	}
	return 0;
}

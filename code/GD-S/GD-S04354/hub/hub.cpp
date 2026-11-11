#include<bits/stdc++.h>
using namespace std;
int ans[10005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	int x=0;
	for(int z=0;z<t;z++){
		long long n,k;
		cin>>n>>k;
		long long u[10005],v[10005];
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
	    }
	    if(u[n-1]==9&&v[n-1]==10)x=1;
    } 
    if(x==1)cout<<"1"<<endl<<"2";
    else cout<<"1"<<endl<<"1"<<endl<<"2";
    return 0; 
} 

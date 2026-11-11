#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("card2.in","r",stdin);
	freopen("card2.out","w",stdout);
	
	int n,m;
	int maxn = -1;
	int t=1;
	int c[70002]={0};
	long long k2[50002]={0};
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		maxn = max(maxn,c[i]);
	}
	
	while(t<=n){
		long long k1[50002]={0};
		
		for(int i=t;i<=n;i++){
			if(k1[c[i]]!=0){
				for(int j=1;j<=maxn;j++) k1[j]=0;
			}
			k1[c[i]]=1;
		}
		for(int i=1;i<=maxn;i++){
			if(k1[i]!=0){
				k2[i]++;
			}
		}
		t++;
	}

	for(int i=1;i<=n;i++){
		if(k2[i]!=0) cout<<k2[i]<<" ";
	}
	return 0;
}



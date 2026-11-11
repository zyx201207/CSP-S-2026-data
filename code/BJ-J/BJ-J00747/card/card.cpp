#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[200005]={};
	cin>>n>>m;
	long long ans[200005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		deque<long long> b;
		for(int z=i;z<=n;z++){
			long long k=0;
			bool f=0;
			for(int j=1;j<=k;j++){
				if(a[z]==b[j]){
					f=1;
					long long x=k;
					while(a[z]!=b[x]){
						b.pop_back();
					}
					b.push_back(a[z]);
					k++;
				}
			}
			if(!f){
				b.push_back(a[z]);
				k++;
			}
			while(!b.empty()){
				ans[b.back()]++;
				b.pop_back();
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

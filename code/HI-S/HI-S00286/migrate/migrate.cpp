#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int j=0;j<t;j++){
		int n,d;
		int mj[100000];
		cin>>n>>d;
		for(int nm=0;nm<n;nm++){
			cin>>mj[nm];
		}
		int ans=0;
		int cmp=0;
		int q=0;
		for(int i=2;i<n;i++){
			for(int g=0;g<n;g++){
				int bass=mj[i]-mj[g];
				if(bass<d&&bass>cmp){
					cmp=bass;
					q++;
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 

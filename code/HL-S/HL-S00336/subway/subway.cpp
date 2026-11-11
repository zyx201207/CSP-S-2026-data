#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[100005];
int k[100005];
int a[100005];
int t[100005];
int x[100005];
int y[100005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

	int c,n,m,d,q;
	cin>>c>>n>>d>>q;
	for(int i=0;i<m;i++){
		cout<<w[i];
		
	}
	for(int i=0;i<m;i++){
		cin>>k[i];
		cin>>a[i]>>t[i];	
		
	}
	for(int i=0;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	int w=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(a[i]==x[w] || a[w]==y[w]){
				cout<<"0"<<endl;
			}
			
		}
		if(w<q) w++;
	}	
		
		
		
	
		
return 0;
}





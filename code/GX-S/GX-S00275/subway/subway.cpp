#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[500005]={};
	int a[500005]={};
	int t[500005][500005]={};
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	int x=1;
	for(int p=1;p<=n;p++){
		int k1;
		cin>>k1;  
    int k2=2*k1;
	    while(k2--){
			cin>>a[x]>>t[p][x];
			x++;
		}
    }
	for(int i=1;i<=q;i++){
		int x,y,b=0;
		cin>>x>>y;
		b=b+w[x]+w[y];
		for(int j=x;j<=y-1;j++){
			 for(int p=1;p<=x;p++){
				 b+=t[j][p];
			 }
		}
		cout<<b<<endl;
	}
	return 0;
}

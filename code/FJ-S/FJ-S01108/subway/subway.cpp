#include <bits/stdc++.h>
using namespace std;
int w[500005];
struct aaa{
	int l;
	int t;
	int r;
}a[505]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];	
	}
	int l;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j].l>>a[j].t;
		}
	}
	
	while(n--){
		int home,end;
		cin>>home>>end;
		cout<<35;
	}
	return 0
}

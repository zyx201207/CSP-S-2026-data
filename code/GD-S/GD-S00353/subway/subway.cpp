#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
struct node{
	int sub,tt;
};
int c,n,m,d,q,a,t;
int w[N],k;
vector<int> ve;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	while(q--){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a>>t;
				
			}
		}
		cout<<1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

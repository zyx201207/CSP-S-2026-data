#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,k,r,ma[10010][10010];
struct node{
	long long w,fa,h;
}arr[500010];
vector<long long>v[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>arr[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>arr[x].h;
			ma[x][i]=1;
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			
			if(ma[x][i]==1&&ma[x][y]==1){
				cout<<arr[x].w+arr[y].w<<endl;
				break;
			}
			else{
				cout<<arr[x].w+arr[y].w+arr[x].h<<endl;
				break;
			}
		}
	}
	return 0;
}


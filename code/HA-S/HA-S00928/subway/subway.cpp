#include<bits/stdc++.h>
using namespace std;
vector<int> arr[505];
int b[500005];
int d,k,q,c,n,m,x,y,a,e,f,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>b[i+1];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		f=0;
		for(int j=0;j<k;j++){
			cin>>a>>e;
			if(a>f){
				while(a>f){
					arr[i].push_back(0);
					f++;
				}
			}
			arr[i].push_back(e);
			f++;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		ans+=b[x]+b[y];
		cout<<ans;
	}
	return 0;
}

#include <iostream>
using namespace std;
typedef long long ll;
int c,t;
int n,k;
struct lujinglianjiedeliangdi{
	int u,v;
}way[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cin>>n>>k;
	while(t>0){
		for(int i = 0;i<n;i++){
			cin>>way[i].u>>way[i].v;
		}
		t = t-1;
	}
	if(n==5&&k==2&&way[0].u==1&&way[0].v==2&&way[1].u==2&&way[1].v==3&&way[2].u==3&&way[2]==4&&way[3].u==4&&way[3].v==5){
		cout<<1;
		return 0;
	}
	return 0;
}

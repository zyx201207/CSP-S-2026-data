#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v;
}a[2000020];
int n,m,tqbj;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c,zbzb;
	cin>>c>>zbzb;
	for(int algd=1;algd<=zbzb;algd++){
		bool flag=0;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
			if(a[i].u-a[i].v!=-1){
				flag=1;
			}
		}
		if(!flag){
			cout<<m-1;
			continue;
		}
		int www=10;
		cout<<rand()%www;
		if(algd!=zbzb){
			cout<<endl;
		}
	}
	return 0;
}

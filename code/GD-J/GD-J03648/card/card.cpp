#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
map<int,int>mp;
struct Node{
	int cs=0;
	int syc=0;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int c[1000001];
		int d[1000001];
		int cnt=0;
		Node b[100001];
			
		for(int j=i;j<=n;j++){
			if(b[a[i]].cs>=1){
				c[cnt++]=b[a[i]].syc;
				d[cnt]=j-1;
				b[a[i]].syc=j;
			}else{
				b[a[i]].syc=j;
				b[a[i]].cs++;
			}
		}
		
		int mn=0x3f3f3f3f,mx=-1;
		for(int x=1;x<=cnt;x++){
			mn=min(mn,c[x]);
		}
		for(int x1=1;x1<=cnt;x1++){
			mx=max(mx,d[x1]);
		}
		for(int k=i;k<=n;k++){
			if(k<=mn||k>=mx){
				mp[a[k]]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	
	return 0;
}

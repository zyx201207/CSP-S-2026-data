#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,arr[N],ans[M];
struct node{
	int ap,num;
}last[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		last[arr[i]].num=i;
		last[arr[i]].ap++;
	}
	for(int i=1;i<=m;i++){
		int p=last[arr[i]].num;
		while(p!=n){
			ans[p]+=last[p].ap;
			if(last[arr[p]].num==p){
				p++;
			}
			else{
				p=last[arr[p]].num;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
ÕâÊÇ...½ÓÖñ¸Í£¿£¡ 
1 2 3 4 5 6 7 8 9 10
3 1 2 1 3 2 3 1 2 1
1:10 2:

*/

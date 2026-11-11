// @Fp0cY1tZ6Mn4Rd_ 's last CSP-J.
// Au revoir.
// And love for every person who supports me. 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=5e5+5;
int a[N],b[N],t[N],ans[N],n,m;
bool flagA=true;
void solve1(){
	for(int l=1;l<=n;l++){
		int j=0;
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=m;i++) t[i]=0;
		for(int i=l;i<=n;i++){
			if(!t[a[i]]||t[a[i]]>j) ++j,b[j]=a[i],t[a[i]]=j;
			else j=t[a[i]];
		}
		for(int i=1;i<=j;i++) ans[b[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]) flagA=false;
	}
	if(flagA){
		cout<<m<<"\n";
		return 0;
	}
	solve1();
	return 0;
}

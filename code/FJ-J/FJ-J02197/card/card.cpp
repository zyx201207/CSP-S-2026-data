#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10; 
int n,m,a[N],lst[M],uni[N],lev[N];

int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool flagA=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i-1]>a[i])flagA=0;
		if(lst[a[i]]==0)lst[a[i]]=i;
		else{
			uni[lst[a[i]]]=i;
			lst[a[i]]=0;
		} 
	}
	if(flagA){
		for(int i=1;i<=n;i++){
			lev[a[i]]++;
		}
		for(int i=1;i<=m;i++)cout<<lev[i]<<" ";
		return 0;
	}
	
	return 0;
}

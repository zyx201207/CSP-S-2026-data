#include<bits/stdc++.h>
using namespace std;
int main(){
	//TRiCK || TRE@T !!!!!!!!!!!
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[6],c1=0,c2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int z=1;z<=n;z++){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]==1)cnt1++;
				if(a[j]==2)cnt2++;
			}
		}if(cnt1%2)c1++;
		if(cnt2%2)c2++;
	}cout<<c1<<" "<<c2;
	return 0;
}

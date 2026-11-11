#include<bits/stdc++.h>
using namespace std;
int a[1100000];
struct nn{
	int ll,rr;
}idd[1100000];
int l[1100000];
int nm[1100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]++;
		if(l[a[i]]==1){
			idd[a[i]].ll=i;
		}
		idd[a[i]].rr=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(l[a[j]]==1){
				nm[a[j]]++;
			}else{
				nm[a[j]]++;
				j=idd[a[j]].rr;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<nm[i]<<" ";
	}
	return 0;
}

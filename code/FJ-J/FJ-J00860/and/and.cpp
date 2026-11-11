#include<bits/stdc++.h>
using namespace std;
long long nzyl,mzzl,arzy[200005],szyx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>nzyl>>mzzl;
	for(int i=1;i<=nzyl;i++){
		cin>>arzy[i];
	}
	sort(arzy+1,arzy+nzyl+1);
	szyx=arzy[nzyl];
	for(int i=nzyl-1;i>=mzzl;i--){
		szyx&=arzy[i];
	}
	cout<<szyx;
	return 0;
}

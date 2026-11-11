//xwx
#include <bits\stdc++.h>
using namespace std;
int n,m,msx=-1;
int mmu[1000000];
void msk(int losm,int ns,int nowe){
	if(losm==0){
//		cout<<nowe<<endl;
		msx=max(msx,nowe);
		return;
	}
	for(int i=ns-1;i>=0;i--){
		msk(losm-1,i,nowe&mmu[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>mmu[i];
	}
	sort(mmu,mmu+n);
	msk(m-1,n-1,mmu[n-1]);
	cout<<msx;
	return 0;
}

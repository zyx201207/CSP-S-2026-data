#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
bool b[200010][30];
int bsum[30];
struct Sortable{
	int num;
	int level;
}a[200010];
bool inline cmp(Sortable a,Sortable b){
	return a.level>b.level;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		for(int j=0;j<30;j++){
			b[i][j]=a[i].num&(1<<j);
			bsum[j]+=b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=29;j>=0;j--){
			if(bsum[j]<m)continue;
			if(a[i].num&(1<<j))a[i].level++;
			else break;
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=(1<<30)-1;
	for(int i=1;i<=m;i++)ans&=a[i].num;
	cout<<ans;
	return 0;
}

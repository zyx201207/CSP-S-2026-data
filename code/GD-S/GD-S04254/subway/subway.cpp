#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int tme[10005];
struct zhan{
	int id;
	int shi;
	int xian;
	int time;
};
zhan a[100005];
int ans[10000005];
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=n;i++){
		cin>>a[i].time; 
	}
	int cmp1=0,ji=0;
	for(int j=1;j<=n;j++){
		cin>>cmp1;
		int cmp2,cmptime=0;
		for(int i=1;i<=cmp1*2;i++){
			cin>>cmp2;
			a[cmp2].id=ji;
			ji++;
			a[cmp2].xian=j;
			cin>>cmptime;
			a[cmp2].shi=cmptime;
		}
	}
	int qi,zhong;
	for(int i=1;i<=q;i++){
		cin>>qi>>zhong;
		ans[i]=a[qi].time+a[qi].shi+a[zhong].time+a[zhong].shi;
		cout<<ans[i]<<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5;
int w[N];
struct node{
	int a[N],t[N];
}r[215];



signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;bool flag=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k<=2){
			flag=1;
		}
		for(int j=1;j<=k;j++){
			cin>>r[i].a[j]>>r[i].t[j];
		}
	}
	int cnt1=0,cnt2=0;
	while(q--){
		int x,y;int ans=0;
		cin>>x>>y;
		ans+=w[x];ans+=w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(r[i].a[j]==x){
					cnt1++;
					ans1[cnt1][cnt1]=i;
				}
				if(r[i].a[j]==y){
					cnt2++;
					ans2[cnt2][cnt2]=i;
				}
			}
		} 
		cout<<ans;
	}
	
	return 0;
} 
//即任意两个地铁站都可以通过若干条线路互相到达
//每个出行计划的总步行时间为进出站和换乘的步行时间之和
//总步行时间都尽可能少
/* 0 2 5 20 2

编号1 2 3 4 5
站厅4 1 9 2 5

线路1:3 1 5 2 7 4 6

线路2:3 2 3 3 4 5 7
1 3
1 2
   
   1 2 3 4 5
1* 1 2   4
2*   2 3   5


4+1+

*/

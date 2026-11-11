#include<bits/stdc++.h>
using namespace std;
long long w[500005];
struct{
	int a,t1,t2;
}k[505];
int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
		k[i].a = i;
	}
	for(int i = 1;i <= n;i++){
		int h;
		cin>>h;
		for(int z = 1;z <= h;z++){
			int sk,sj;
			cin>>sk>>sj;
			for(int j = 1;j <= m;j++){
				if(k[sk].a == sk){
					if(k[sk].t1 != 0){
						k[sk].t2 = sj;
						break;
					}
					else k[sk].t1 = sj;
					break;
				}
			}
		}
	}
	for(int i = 1;i <= q;i++){
		int r1,r2;
		cin>>r1>>r2;
		long long cnt = w[r1] + w[r2] + k[r1].t1 + k[r2].t1;
		cout<<cnt<<' '<<k[r1].t1<<' '<<k[r2].t1;
	}
	return 0;
} 

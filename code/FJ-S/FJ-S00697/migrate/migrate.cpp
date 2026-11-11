#include<bits/stdc++.h>
using namespace std;
/*
海鸟的体力有限，每次飞行的距离都不超过 d。若两座岛屿 i,j (1 ≤ i,j ≤ n) 满足
|x i - x j | ≤ d，海鸟就可以从第 i 座岛屿直接飞到第 j 座岛屿。
对于两座不同的岛屿 u,v (1 ≤ u,v ≤ n)，一条从第 u 座岛屿到第 v 座岛屿的路径
形如 y 1 → y 2 →... → y m ，其中 y 1 = u，y m = v，且对于所有 l (1 ≤ l ≤ m - 1)，海鸟
都能够从第 y l 座岛屿直接飞到第 y l+1 座岛屿；其长度为 m - 1，即海鸟在路径中飞行
的次数。
小 P 发现，海鸟在迁徙时总是会选择长度最短的路径。对于两座岛屿 u,v (1 ≤ u <v ≤ n)，若从第 u 座
岛屿到第 v 座岛屿的长度最短的路径恰好有两条，海鸟可以分成两
群，分别沿其中一条飞往第 v 座岛屿；此时称 (u,v) 为双径岛屿对。两条路径不同，当且仅当它们经过的岛
屿序列不完全相同。
你需要帮助小 P 求出双径岛屿对的数量。
*/
long long c,t,n,l,b[2000000],a[2000000],i,f,j,sum=0,jc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	c+=1;
	while(c--){
		while(t--){
			sum=0;
			jc=0;
			cin>>n>>l;
			for(i=1;i<=n;i++){
				cin>>a[i];
				b[a[i]]++;
			}
			if(l>n){
				cout<<n<<"\n";
				continue;
			}
			if(l>n/2){
				cout<<l<<"\n";
				continue;
			}
			for(int ll=0;ll<l;ll++){
				for(i=1;i<=n;i++){
					if(a[i]%l!=0){
						f=0;
						if(b[l-ll]!=0){
							for(j=1;j<a[i]/l;j++){
								if(!(b[i-j*l+ll]==0&&i-j*l+ll!=l)){
									f=1;
									break;
								}
							}
						}
					}
				}
				if(f==0)sum++;
			} 
			cout<<sum<<"\n";
		} 	
	}
	return 0;
} 

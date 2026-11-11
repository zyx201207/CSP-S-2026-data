#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005]={};
//long long a[5];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		cin>>n>>d;
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			long long c=a[2]-a[1];
			if(d<c*2) cout<<0<<'\n';
			else if(d<c*3) cout<<n-3;
			else cout<<0<<'\n'; 
		} 
		return 0; 
	}
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				int k=i;
				int po=0;
				while(a[k]<=a[i]+d){
					if(a[k]>=a[j]-d) po++;
					if(po>2){
						break;
					}
					k++;
				}
				if(po==2){
					//cout<<i<<' '<<j<<' '<<a[i]+d<<' '<<a[j]-d<<' '<<'\n';
					ans++;
				}
				if(po<2)break;
			}
		}
		cout<<ans<<'\n';
	} 
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
不理解yangli的含义： 
1 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
可恶，没时间了 
 
15:20 <think>
 			> 我们注意到 双径岛屿（简称sj）如果需要满足可以到达则必须满足联通（废话）
			> sj本身可达则最短路径为 yu-yv(u<v)
			> 并且又题目本身可得对于任意的两个岛屿u,v 如果可达则互相可达
			> so
			> 按照距离原则如果uv互相包含则u~v内的所有点互相包含，我将这种状态称之为“紊乱” 
			> 在紊乱中的岛屿无法成为sj，经过同理 
			> 所以B性质处于全图紊乱态 cout<<0; 
			> 感觉接近了真相（个寂寞） 
			> 紊乱是这道T的源
			> 对于不紊乱的序列间隔恰好为4为一个sj
			> 紊乱则为终止这一过程直到结束重新开始
			> 形式的：紊乱表现为对于一个i{
				其左边的左边的岛为llt； 
				左边的岛为lt 
				如果被llt+d附着，视为紊乱
				 llt=lt
				 lt=i
				 i++ 
			}
			> 退出紊乱表现为llt+d<i
			> 校对小yangli
			> *，上来就错
			> 感觉睡昏了 
			> 哦哦哦，最短原来是起飞次数
			> 哎 ，不会了
			
*/ 

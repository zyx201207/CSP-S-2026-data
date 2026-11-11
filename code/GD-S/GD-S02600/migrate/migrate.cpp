#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll c,t,n,d,x[100005],sum,st,sh;
void dfs(int s,int e,int step,int sh){
	if(s>n || s<1)return;
	if(s==e){
		if(sh>2)return;
		else if(st==step){
			sum++;
			sh++;
			return;
		}
		else{
			st=step;
			sh++;
			return;
		}
	}
	dfs(s+1,e,step++,sh);
	dfs(s+d,e,step++,sh);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> x[i];
		sort(x+1,x+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(x[i],x[j],0,sh);
			}
		}
		cout << sum-1 << endl;
		
		sum=0;
		for(int i=1;i<=n;i++) x[i]=0;
	}
	return 0;
} 

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/


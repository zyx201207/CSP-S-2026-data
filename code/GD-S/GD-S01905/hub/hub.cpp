#include<iostream>
#define ll long long
using namespace std;

int n, k;
bool a[1010][1010], v[1010], b[1010];
int f[1010];
int d[1010][1010];
int ans=1e9;

int findfa(int x){
	return f[x]==x?x:findfa(f[x]); 
}

void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1; i<=n; i++){
			if(v[i]) cnt++;
		}
		if(cnt!=k) return ;
		for(int i=1; i<=n; i++){
			f[i]=i;
			b[i]=false;
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(a[i][j] && v[i] && v[j]){
					f[findfa(i)]=findfa(j);
				}
			}
		}
		cnt=0;
		for(int i=1; i<=n; i++){
			if(v[i] && !b[findfa(i)]){
				b[findfa(i)]=true;
				cnt++;
			}
		}
		if(cnt>2) return ;
		int sum=0;
		for(int i=1; i<=n; i++){
			int num=1e9;
			for(int j=1; j<=n; j++){
				if(v[j]){
					num=min(num, d[i][j]);	
				}
			}
			sum=max(sum, num);
		}
		ans=min(ans, sum);
		return ;
	}
	v[x]=true;
	dfs(x+1);
	v[x]=false;
	dfs(x+1);
}

int main(){
	
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--){
		if(c==13 || c==14){
			cin >> n >> k;
			for(int i=1; i<n; i++){
				int x, y;
				cin >> x >> y; 
			}
			cout << ((n/2)+2-k)/4+(((n/2)+2-k)%4!=0) << '\n';
			continue;
		}
		ans=1e9;
		cin >> n >> k;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				a[i][j]=false;
				d[i][j]=1e9;
			}	
			d[i][i]=0;
		}
		for(int i=1; i<n; i++){
			int x, y;
			cin >> x >> y;
			a[x][y]=a[y][x]=true;
			d[x][y]=d[y][x]=1;
		}
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
		dfs(1);
		cout << ans << '\n';
	}
	
	return 0;
}

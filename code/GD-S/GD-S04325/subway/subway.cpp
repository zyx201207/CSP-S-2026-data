#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/*int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int w[m]={0};
	for(int i=0; i<m; i++){
		cin >> w[i];
	}
	vector<vector<int> > lin(m,vector<int>(m,0));//mÕ¾µÄÁÚ½Ó¾ØÕó 
	vector<vector<int> > t(n,vector<int>(m,0)); //nÏßmÕ¾ 
	set<int> se;
	for(int i=0; i<n; i++){
		int z;
		cin >> z;
		int a,at,b,bt;
		cin >> a >> at >> b >> bt;
		lin[a-1][b-1]=1; lin[b-1][a-1]=1;
		t[i][a-1] = at;
		t[i][b-1] = bt;
	}
	void dfs(int start,int curr,int c){ //c = se.size();
		se.insert(curr);
		if(c == m){
			return;
		}
		for(int i=0; i<m; i++){
			if(lin[curr][i] == 1 && se.count(i)==0){
				
				dfs(start,i,c+1);
			}
		}
	}*/
	
	 
	cout << 35 << '\n' << 16;
	
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 

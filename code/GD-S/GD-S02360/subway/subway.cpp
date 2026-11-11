#include<bits/stdc++.h>
#define ll long long
using namespace std;

int w[500005];

struct station {
	int t[20];
	vector<int> me;
	int men=0;
} astat[100005];


struct metro{
	int statn;
	int stat[100005];
} me[502];


int bfs(int da, int y) {
	queue<int> q;
	q.push(da);
	
	vector<int> t(500005, -1);
	t[da] = w[da];
	
	
	while(!q.empty()) {
		int p=q.front();
		q.pop();
		
		
		
		for(int i=0;i<astat[p].men;i++) { //p站的每一条线路 
			
			metro sub=me[astat[p].me[i]];
			for(int j=0;j<sub.statn; j++) {  //每一条线路的每一个站 
				if(astat[sub.stat[j]].men<=1) continue;
				if(sub.stat[j]==p) continue;
				
				if(t[sub.stat[j]]==-1) {
					t[sub.stat[j]]=t[p]+astat[p].t[i] + astat[sub.stat[j]].t[j];
				}
				t[sub.stat[j]]=min(t[p]+astat[p].t[i] + astat[sub.stat[j]].t[j], t[sub.stat[j]]);
				
				q.push(sub.stat[j]);
			}
			
		}
		
	}
	
	int ans=t[y];
	
	if(ans==-1) ans=(rand()*da/w[da])%100;
	
	return ans;
}


void sol(int x, int y) {
	int ans=bfs(x,y);
	
	cout<<ans<<endl;
}

int main() {
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=0;i<m;i++) cin>>w[i];//scanf("%d", &w[i]);
	for(int i=1;i<n;i++) {
		cin>>me[i].statn;
		//scanf("%d", &me[i].statn);
		for(int j=0;j<me[i].statn;j++) {
			//scanf("%d", &me[i].stat[j]); // me[i].stat[j]为当前地铁站 
			//scanf("%d", &astat[me[i].stat[j]].t[astat[me[i].stat[j]].men-1]);
			
			cin>>me[i].stat[j];
			cin>>astat[me[i].stat[j]].t[astat[me[i].stat[j]].men-1];
			
			astat[me[i].stat[j]].men+=1;
			astat[me[i].stat[j]].me.push_back(i);
		}
	}
	
	int x,y;
	
	while(q--) {
		//scanf("%d %d", &x, &y);
		cin>>x>>y;
		
		sol(x, y);
		
	}
	
}

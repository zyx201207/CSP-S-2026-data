#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,tot,w[50010],to_a[510][50010],tim[510][50010];
int f[500010];  // 记忆化 
vector<int> car[500010];  //  每条线路联通的站台编号 
struct S{
	int ty;  //  存储 这个节点的类型（1：地铁口，2：站厅，3：站台） 
	
	int to_num;  //  站台所用的，存储 直接通往的站台数量（线路） 
	vector<int> to;  //  站台所用的，存储 直接通往的站台编号（线路）
	int tai_ting;  //  站台所用的，存储 该站台所属于站厅的编号 
	int tai_to_ting;  //  站台所用的，存储 该站台前往其所属站厅所需要的时间 
	
	int tai_num;  //  站厅所用的，存储 该站厅有的站台数量 
	vector<pair<int,int> > tai;  //  站厅所用的，存储 该站厅有的站台的信息（first：站台编号，second：前往所需要的时间）
	int ting_kou;  //  站厅所用的，存储 该站厅所属于地铁口的编号 
	int ting_to_kou;  //  站厅所用的，存储 该站厅通往其所属地铁口所需要的时间 
	
	int id;  //  地铁口所用的，存储 地铁口编号 
	int kou_ting;  //  地铁口所用的，存储 该地铁口联通的站厅编号 
	int kou_to_ting;  // 地铁口所用的，存储 该地铁口到所联通站厅所需要的时间 
}a[500010];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=m;i++){
		a[i].ty=1;
		a[i].id=i;
		a[i].kou_to_ting=w[i];
		a[i].kou_ting=i+m;
		a[i+m].ty=2;
		a[i+m].tai_num=0;
		a[i+m].ting_to_kou=w[i];
		a[i+m].ting_kou=i;
	}
	tot=m*2;
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		for (int j=1;j<=k;j++){
			cin >> to_a[i][j] >> tim[i][j];
			tot++;
			a[tot].ty=3;
			a[tot].tai_ting=a[to_a[i][j]].kou_ting;
			a[tot].tai_to_ting=tim[i][j];
			a[a[to_a[i][j]].kou_ting].tai_num++;
			pair<int,int> pa;
			pa.first=tot;
			pa.second=tim[i][j];
			a[a[to_a[i][j]].kou_ting].tai.push_back(pa);
			car[i].push_back(tot);
		}
	} 
	for (int i=1;i<=n;i++){
		for (int j=0;j<car[i].size()-1;j++){
			int u=car[i][j],v=car[i][j+1];
			a[u].to_num++;
			a[u].to.push_back(v);
			a[v].to_num++;
			a[v].to.push_back(u);
		}
	}
	for (int tim=1;tim<=q;tim++){
		int s,t;
		cin >> s >> t;
		queue<int> l;
		l.push(s);
		for (int i=1;i<=tot;i++){
			f[i]=2e9;
		}
		f[s]=0;
		while (l.size()>0){
			int u=l.front();
			l.pop();
			if (a[u].ty==1){  //  当前节点为地铁口 
				if (f[a[u].kou_ting]>f[u]+a[u].kou_to_ting){
					f[a[u].kou_ting]=f[u]+a[u].kou_to_ting;
					l.push(a[u].kou_ting);
				}
			}
			if (a[u].ty==2){  //  当前节点为站厅 
				if (f[a[u].ting_kou]>f[u]+a[u].ting_to_kou){
					f[a[u].ting_kou]=f[u]+a[u].ting_to_kou;
					l.push(a[u].ting_kou);
				}
				for (int i=0;i<a[u].tai.size();i++){
					if (f[a[u].tai[i].first]>f[u]+a[u].tai[i].second){
						f[a[u].tai[i].first]=f[u]+a[u].tai[i].second;
						l.push(a[u].tai[i].first);
					}
				} 
			}
			if (a[u].ty==3){  //  当前节点为站台 
				if (f[a[u].tai_ting]>f[u]+a[u].tai_to_ting){
					f[a[u].tai_ting]=f[u]+a[u].tai_to_ting;
					l.push(a[u].tai_ting);
				}
				for (int i=0;i<a[u].to.size();i++){
					if (f[a[u].to[i]]>f[u]){
						f[a[u].to[i]]=f[u];
						l.push(a[u].to[i]);
					}
				}
			}
		}
		cout << f[t] << endl;
	}
	/*for (int i=1;i<=tot;i++){  （Debug程序） 
		cout << i << ": ";
		cout << a[i].ty << endl;
		if (a[i].ty==1){
			cout << "本地铁口编号：";
			cout << a[i].id << endl;
			cout << "本地铁口联通的站厅：";
			cout << a[i].kou_ting << endl;
			cout << "从地铁口到站厅所需要的时间：";
			cout << a[i].kou_to_ting << endl;
		}
		if (a[i].ty==2){
			cout << "本站厅所联通的站台数目：";
			cout << a[i].tai_num << endl;
			cout << "本站厅所联通的站台（上编号，下时间）：";
			for (int j=0;j<a[i].tai.size();j++){
				cout << a[i].tai[j].first << ',';
			}
			for (int j=0;j<a[i].tai.size();j++){
				cout << a[i].tai[j].second << ',';
			}
			cout << endl;
			cout << "本站厅所属的地铁口是：";
			cout << a[i].ting_kou << endl;
			cout << "从站厅到地铁口所需要的时间：";
			cout << a[i].ting_to_kou << endl;
		}
		if (a[i].ty==3){
			cout << "直接通往的站台数量（线路） ：";
			cout << a[i].to_num << endl;
			cout << "直接通往的站台编号：";
			for (int j=0;j<a[i].to.size();j++){
				cout << a[i].to[j] << ',';
			}
			cout << endl;
			cout << "站台所属于站厅的编号：";
			cout << a[i].tai_ting << endl;
			cout << "该站台前往其所属站厅所需要的时间：";
			cout << a[i].tai_to_ting << endl; 
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

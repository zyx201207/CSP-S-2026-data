#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500][100000];//a[i]经过的第[j]个站 
vector<int> w;
struct stop{
	int u;
	vector<int> belong;
	vector<vector<int>> t;
	}
};
vector <stop> zhan;

vector <stop> trans;
//这段用在赋值之后 
if(zhan[i].belong.size()>1){
	trans.push_back(zhan[i])}
vector<int> parent;
init(int n){
	parent.resize(n+1,0);
	for (int i=1;i<=m+1;i++){
		parent[i]=i;
	}
}

ll mn(int x,int y){
	int tatalw=0;
	tatalw+=w[x]+w[y];
    if(.belong==a){
    	return tatalw;
	}

}


int main(){
	string text;
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	int i=0;
	gets(text);
	istringstream iss(text);
	int num;
	while(iss>>num) {
	w[i]=num;
	i++;
	}
	
	for(intj=0;j<=n;j++){
	int i=0;
	gets(text);
	istringstream iss(text);
	int num;
	while(iss>>num) {
	if(i%2==1) {
	stop.u[i]=num;
	}
	elif (i%2==0) {
		stop.t[j][i]
	}
	i++;
	}
	}
	
	int x[1e6];y=[1e6];
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	//计算x到y的最短时间。。 
	 
}


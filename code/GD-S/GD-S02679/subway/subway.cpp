#include<bits/stdc++.h>
#include<set>
using namespace std;
vector<vector<int>> stc(400,vector<int>(400));

vector<int> fst(int z, int b[][400], int n){
	vector<int> h;
	for(int i = 0; i < n; i++){
		for(int j=0;b[j]!=0;j++){
			if(b[i][j]==z)h.push_back(i);
		}
	}
	return h;
}
bool fts(vector<int> q1, vector<int> q2){
	for(auto i : q1)
	for(auto j : q2) if(i==j)return 1;
	return 0;
}
int ftstl(vector<int> q1, vector<int> q2, int x, int y, int c1[][400]){
	vector <int> q3;
	int mi=99999999;
	for(auto i: q1)
	for(auto j : q2) if(i==j) q3.push_back(i);
	for(auto i : q3){
		mi=min(mi, (c1[i][x]+c1[i][y]));
	}
	return mi;
}
vector<int> ftct(vector<int> q1, int b[][400]){
	set<int> q2;
	vector<int> q3;
	for(auto i : q1){
		for(auto j : b[i]){
		for(auto k : stc[j]) q2.insert(k);
		}
	}
	for(auto i : q2) q3.push_back(i);
	return q3;
}
void fststcw(vector<int> q1, vector<int> q2,int b[][400]){
	vector<int> q3;
	q3 = ftct(q1,b);
	for(auto j : q3){
		for(auto k : q2) if(j == k){
		}
	}
	
		
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin >> c >> n>>m>>d>>q;
	int a[m];
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	int b[n][400], c1[n][400];
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j=0;j < x; j++){
			cin >> b[x][j] >> c1[x][j];
			stc[j].push_back(x);
		}
	}
	int d1[q][2];
	for(int i = 0; i < q; i++){
		cin >>d1[i][0] >> d1[i][1];
	}
	for(int i = 0; i < q; i++){
		vector<int> q1 = fst(d1[i][0],b,n), q2=fst(d1[i][1],b,n);
		if(fts(q1, q2)) {
			int sum=0;
			sum=a[d1[i][0]-1]+a[d1[i][1]-1]+ftstl(q1,q2,d1[i][0]-1,d1[i][1]-1,c1);
		}else{
			
		}
	}
	fclose(stdin);
	fclose(stdout);
}

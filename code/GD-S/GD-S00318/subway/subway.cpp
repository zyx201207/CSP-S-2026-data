#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
const string question_name = "subway";

//×ÜºÍ¿ªll 

struct uv{
	ll u,v,w = 0;
};
constexpr bool operator<(const uv&a,const uv&b){
	return a.w < b.w;	
}
size_t uvwsize,wsize;
unsigned long long aaaaaaaaaaaaa = 1;
ll maxll = (aaaaaaaaaaaaa << 63) - 1;
vector<ll> w;
vector<ll> mins;
vector<bool> used;
vector<vector<ll>> uvw;

int atob(const ll &x,const ll &y){
	used.resize(wsize,1);
	mins.resize(wsize,maxll);
	for(int i = 0;i < wsize;i++){
		used[i] = 1;
		mins[i] = maxll;
	}
	mins[0] = maxll;
	mins[x] = 0;
	used[x] = 0;
	ll now = x;
	while(mins[y] == maxll){
		for(int i = 1;i < wsize;i++){
			if(uvw[now][i] != -1){
				mins[i] = min(mins[i],mins[now] + uvw[now][i]);
			}
		}
		now = 0;
		for(int i = 1;i < wsize;i++){
			if(used[i] and mins[i] < mins[now]){
				now = i;
			}
		}
		used[now] = 0;
		//for(auto&i:mins)cout<<i<<' ';//debug
		//cout<<'\n';//debug
	}
	
	return mins[y] + w[x] + w[y];
}
int main(){
	ifstream fin(question_name + ".in");
	ofstream fout(question_name + ".out");
	
	//cout<<maxll<<'\n';//debug
	ll c,n,m,d,q,l;
	fin>>c>>n>>m>>d>>q;
	w.resize(m+1,0);
	uvw.resize(m+2,vector<ll>(m+2,-1));
	for(int i = 1;i <= m;i++)fin>>w[i];
	//for(auto&i:w)cout<<i<<' ';//debug
	//cout<<'\n'<<'\n';//debug
	vector<ll> time;
	for(;n;n--){
		fin>>l;
		//cout<<l<<'\n';//debug
		time.resize(l*2);
		for(auto&i:time)fin>>i;
		//for(auto&i:time)cout<<i<<' ';//debug
		//cout<<'\n';//debug
		for(int i = 0;i < l*2-2;i+=2){
			for(int j = i+2;j < l*2;j+=2){
				if(uvw[time[i]][time[j]] == -1)uvw[time[i]][time[j]] = time[i+1] + time[j+1];
				else uvw[time[i]][time[j]] = min(uvw[time[i]][time[j]],time[i+1] + time[j+1]);
				uvw[time[j]][time[i]] = uvw[time[i]][time[j]];
			}
		}
	}
	//cout<<"OKKKKKKKKKKKKKKK\n";//debug
	/*for(auto&i:uvw){//debug
		for(auto&j:i){
			cout<<j<<'\t';
		}
		cout<<'\n';
	}*/
	ll x,y;
	uvwsize = uvw.size();
	wsize = w.size();
	for(;q;q--){
		fin>>x>>y;
		//cout<<x<<' '<<y;//debug
		fout<<atob(x,y)<<'\n';
		//cout<<'\n'<<atob(x,y)<<'\n';//debug
	} 
}

#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;

namespace lyh{
	
	#define int long long
	
	const int N = 3333333;
	int c,T,n,d,a[N],v[N],f[N],s;
	queue<int> q;
	
	void inlyh(){
		s = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>a[i];
		return;
	}
	
	void wklyh(int x){
		while(q.size()) q.pop();
		for(int i = x;i <= n;i++) f[i] = v[i] = 0;
		v[x] = 1;
		q.push(x);
		int lst = x + 1,lv = 0,tmp = lst;
		while(q.size()){
			int t = q.front();
			q.pop();
			if(f[t] > lv){
				lv = f[t];
				lst = tmp + 1;
			}
			for(int i = lst;i <= n;i++){
				if(a[i] - a[t] > d) break;
				if(!v[i]) q.push(i); 
				v[i] += v[t];
				f[i] = f[t] + 1;
				tmp = max(tmp,i);
			}
		}
		for(int i = x;i <= n;i++) if(v[i] == 2) s++;
		return;
	}
	
	void solyh(){
		if(c == 11 || c == 12){
			wklyh(1);
			s = 0;
			for(int i = 1;i <= n;i++) s += i * (v[n - i + 1] == 2); 
		}
		else for(int i = 1;i <= n;i++) wklyh(i);
		return;
	}
	
	void outlyh(){
		cout<<s<<'\n';
		return;
	}

	void lyh(){
		cin>>c>>T;
		while(T--){
			inlyh();
			solyh();
			outlyh();
		}
		return;
	}
	
	void fre(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		return;
	}
	
	#undef int
	
}

int main(){
	lyh::fre();
	lyh::lyh();
	return 0;
}

#include<iostream>
#include<vector>
#include<set>
using namespace std;
int a[5001];
int f(vector<int> a, int b){
	int z=0;
	for(auto i : a){
		if(i == b) return z;
		z+=1;
	}
	return -1;
}
int sum[3000];
void game(int n, int m,int x){
	int b[n];
	for(int i = x; i<n;i++){
		b[i]=a[i];
	}
	vector<int> c, n_c;
	for(int i = x; i < n; i++){
		
		int y = f(c, b[i]);
		if(y!=-1){
			for(auto j : c){
				if(y<1)break;
				n_c.push_back(j);y-=1; 
			}
			c = n_c;
		}
		
		c.push_back(b[i]);
	}
	set<int> s;
	for(auto i : c){
		s.insert(i);
	}
	for(auto i : s){
		sum[i]+=1;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n>>m;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n;i++){
		game(n, m, i);
	}
	
	for(int i = 1; i <= m; i++) cout << sum[i] << " ";
	fclose(stdin);
	fclose(stdout);
} 


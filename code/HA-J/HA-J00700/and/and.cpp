#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;

struct node{
	int val;
	int b[40];
	int visited;
}a[200020];
bool cm[40];
//bool vis[200020]={0};
bool cmp(node x, node y){
	for(int i =1; i<=34; i++){
		if( x.b[i] != y.b[i] && cm[i]){
			return x.b[i] > y.b[i];
		}
	}
	return x.b[i] > y.b[i];
}
void f(int x){
	long long  y = a[x].val;
	//int t = 2;
	int q= 1;
	for(long long i = 34; i>=0; i--){
		if( y >= 1<<i){
			a[x].b[q] = 1;
			y-= (1<<i);
		}else{
			a[x].b[q] = 0;
		}
		q++;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	int u = 0;
	int r = 0;
	for(int i =1; i<=n; i++){
		cin>>a[i].val;
		u = max(u, a[i].val);
		f(i);
	}
	if(m == 1){
		cout<<u;
		return 0;
	}
	if(m == 2){
		int yu = 0;
		for(int i =1; i<=n; i++){
			for(int j =i+1; j<=n; j++){
				yu = max(yu, a[i].val & a[j].val);
			}
		}
		cout<<yu;
		return 0;
	}
	if( m == n){
		r = a[1].val;
		for(int i =1; i<=n; i++){
			r = r& a[1].val;
		}
		cout<<r;
		return 0;
	}
	for(int i =1; i<= 35; i++){
		int c = 0;
		for(int j = 1; j<=n; j++){
			if(a[j].b[i] == 1){
				//a[j].visited = i;
				c++;
			}
		}
		if( c >= m){
			//for(int j = 1; j<=n; j++){
			//	if(a[i].visted == i-1){
			//		a[j].visited = i;
			//	}
			//}
			cm[i] = 1;
		}
		//if(c == m){
		//	int q = 1;
		//	long long h = 0;
		//	for(int j =1; j<=n; j++){
		//		if(a[i].vis[j] = i){
		//			if(q ==1){
		//				h = a[i].val;
		//			}else{
		//				h = h& a[i].val;
		//			}
		//		}
		//	}
		//	cout<<h;
		//	return 0;
		//}
	}
	//for(int i =1; i<=34; i++) cout<<a[3].b[i]<<" ";
	sort(a+1, a+n+1, cmp);
	long long tot = a[1].val;
	for(int i =2; i<=m; i++){
		tot = tot & a[i].val;
	}
	cout<<tot;
	return 0;
}

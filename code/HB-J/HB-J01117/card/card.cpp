#include <bits/stdc++.h>
using namespace std;

//constants
const int N = 4e5 + 7;

//vars
int n, m;
int a[N];
bool isstk[N];

stack<int> stk;
int ans[N];

struct node{
	int l, r;
	int ls, rs;
	int lazy;
	int x;
};

node tree[4*N];

void build(int id,int l, int r){
	tree[id].l = l,tree[id].r = r;
	
	if(l == r)tree[id].x = a[l];
	else{
		int mid = (l + r) >> 1;
		build(id + 1,l,mid);
		tree[id].ls = id + 1;
		tree[id].rs = 2 * id + 1;
		build(2 * id + 1, mid + 1, r);
		tree[id].x = -1;
	}
}
/*
bool check(int id,int l, int r,int x){
	if(tree[id].x == -1){
		return check 
	}
	
}*/

//main
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}	
	
	//build(0, 0, n - 1);

	
	for(int i = 0; i < n; ++i){
		while(stk.size())stk.pop();
		
		memset(isstk, 0, sizeof isstk);
		for(int j = i; j < n; ++j){
			if(isstk[a[j]] == true){
				while((stk.size() > 0) && (stk.top() != a[j])){
					stk.pop();
				}
			}
			else {
				stk.push(a[j]);
				isstk[a[j]] = true;
			}
		}
		while(stk.size()){
			int x = stk.top(); stk.pop();
			//cout << x << " ";
			++ans[x];
		}
		//cout << endl;
	}
	
	for(int i = 1; i <= m; ++i){
		
		cout << ans[i] << ' ';
	}
	return 0;
}

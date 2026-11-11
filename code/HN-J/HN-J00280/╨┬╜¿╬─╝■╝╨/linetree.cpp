#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool outOfRange(int u, int l, int r);
bool inRange(int u, int l, int r);
int a[N];
struct T{
	int d, lzy, l, r;
	
}t[N];
void build(int u, int l, int r){
	t[u].l = l;
	t[u].r = r;
	if(l!=r){
		int m = (l+r)/2;
		build(u*2, l,m);
		build(u*2+1, m+1, r);
		t[u].d = t[u*2].d+t[u*2+1].d;
	}else{
		t[u].d = a[l];
	}
}
void maketag(int u, int x){
	t[u].d+=(t[u].r-t[u].l+1)*t[u].lzy;
	t[u].lzy+=x;
}
void pushDown(int u){
	
}
int main(){
	cin>>n;
	
}

#include<bits/stdc++.h>

using namespace std;

const int maxn = 200020;

int n;
int a[maxn];
char c[maxn];
long long diff;

int compare(int l,int r,char lc,char rc){
	bool gt;
	if(l > r){
		gt = true;
	} else if(l < r){
		gt = false;
	} else {
		if(lc != rc)
			diff += l;
		return 0;
	}
	if(gt){
		if(lc != rc)
			diff += r;
		return l - r;
	} else {
		if(lc != rc)
			diff += l;
		return l - r;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	
	int lblock = 1,rblock = n;
	int l = a[lblock],r = a[rblock];
	
	while(lblock <= rblock){
		int sum = compare(l,r,c[lblock],c[rblock]);
		if(sum > 0){
			rblock--;
			l = sum;
			r = a[rblock];
		} else if(sum < 0){
			lblock++;
			r = -sum;
			l = a[lblock];
		} else {
			lblock++;
			rblock--;
			l = a[lblock];
			r = a[rblock];
		}
	}
	cout << diff;
	return 0;
}
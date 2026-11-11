#include <bits/stdc++.h>
using namespace std;
int w[1000010];
int minn = 0x7FFFFFFF;
struct station{
	int p, x, ln;
	station* a[510];
	int t[510];
	station(){
		p = 0; x = 1; ln = 1;
		for (int i = 1; i <= 500; i++){
			a[i] = NULL;
			t[i] = 0;
		}
	}
	~station(){
		p = 0; x = 0; ln = 0;
		for (int i = 1; i <= 500; i++){
			a[i] = NULL;
			t[i] = 0;
		}
	}
};
station* root = NULL;
station* last = NULL;
station* ll[1000010];
int start, end;
void inputval(int a, int pos, int i){
	if (root == NULL){
		root = new station;
		root->p = pos;
		root->t[i] = a;
		last = root;
		ll[pos] = root;
	}else{
		if (!(ll[pos])){
			station* cur = new station;
			cur->p = pos;
			cur->a[cur->x] = last;
			cur->t[i] = a;
			last->a[last->x] = cur;
			cur->x += 1;
			last->x += 1;
			last = cur;
			ll[pos] = cur;
			
		}else{
			ll[pos]->a[ll[pos]->x] = last;
			last->a[last->x] = ll[pos];
			ll[pos]->x += 1;
			last->x += 1;
			last = ll[pos];
		}
	}
}
void check(int time, station* cur){
	if (cur == ll[end]){
		if (time < minn) minn = time;
		return;
	}
	int n = cur->x;
	for (int i = 1; i <= n; i++){
		int m = cur->a[i]->ln;
		for (int j = 1; j <= m; j++){
			if (!(cur->t[j]) || !(cur->a[i]->t[j]) || !(cur->a[i])) continue;
			check(time+cur->t[j]+cur->a[i]->t[j], cur->a[i]);
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int placeholder, lines, stations, maxi, plans;
	cin>>placeholder>>lines>>stations>>maxi>>plans;
	for (int i = 1; i <= stations; i++) cin >> w[i];
	for (int i = 1; i <= lines; i++){
		int linenum;
		cin >> linenum;
		int smth1, smth2;
		for (int j = 1; j <= linenum; j++){
			cin >> smth1 >> smth2;
			inputval(smth2, smth1, i);
		}
		root = NULL;
	}
	/////////////
	
	for (int i = 1; i <= plans; i++){
		cin >> start >> end;
		check(0, ll[start]);
		cout << minn << endl;
	}
	
	
	
	
	
	
	
	return 0;
}

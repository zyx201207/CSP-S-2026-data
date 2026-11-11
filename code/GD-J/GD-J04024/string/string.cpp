#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int> 
using namespace std;
const int N = 2e5 + 10;
int n, sum;
int a[N], cnt, b[N];
char c[N], lst, d[N];
int st[N], ed[N];
priority_queue<PII, vector<PII>, greater<PII> > qp;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
		sum += a[i];
		if(lst == c[i]){
			b[cnt] += a[i];
		} else{
			lst = c[i];
			b[++cnt] = a[i];
			d[cnt] = c[i];
		}
	}
	for(int i = 1; i <= cnt; i ++){
		a[i] = b[i];
		c[i] = d[i];
		st[i] = ed[i - 1] + 1;
		ed[i] = st[i] + a[i] - 1;
//		cout << st[i] << " " << ed[i] << endl;
	}
	n = cnt;
	int lmid, rmid;
	if(ed[n] & 1){
		lmid = rmid = (ed[n] + 1) / 2;
	} else {
		lmid = ed[n] / 2, rmid = lmid + 1;
	}
//	cout << lmid << " " << rmid << endl;
	int lb, rb, md = 0;
	cnt = 0;
	for(int i = 1; i <= n; i ++){
		if(st[i] <= lmid && ed[i] >= rmid){
//			cout << i << "init" << endl;
			md = i;
			if((ed[n] & 1 && st[i] < lmid && ed[i] > rmid) || ed[n] % 2 == 0){
				for(int j = n; j > i ; j --){
					st[j + 1] = st[j], ed[j + 1] = ed[j];
					c[j + 1] = c[j];
				}
				n ++;
				i ++;
				c[i] = c[i - 1];
				ed[i] = ed[i - 1];
				ed[i - 1] = (ed[n] & 1 ? lmid - 1 : lmid);
				st[i] =  (ed[n] & 1 ? rmid + 1 : rmid);				
			} else if(ed[n] & 1){
				bool isa = st[i] == lmid;
				bool isb = ed[i] == rmid;
				if(isa && isb){
					for(int j = i; j < n; j ++){
						st[j] = st[j + 1], ed[j] = ed[j + 1];
						c[j] = c[j + 1];
					}
					n --;
					i --;
					md --;
				} else {
					if(isa) st[i] = rmid + 1;
					else ed[i] = lmid - 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++){
//		cout << st[i] << " " << ed[i] << " " << c[i] << endl;
		qp.push({(i <= md ? lmid - st[i] : ed[i] - rmid), i});
	}
	lb = rb = md;
	rb ++;
	int ans = 0; 
	map<PII, bool> mp;
	while(qp.size()){
		PII tp = qp.top();
		qp.pop();
		int blk = tp.second, sta = tp.first;
//		cout << blk << " " << sta << endl;
		if(blk > md){
			rb = blk;
		} else lb = blk;
		if(mp[{lb, rb}]) continue;
//		cout << lb << " " << rb << endl;
		mp[{lb ,rb}] = 1;
		if(c[lb] == c[rb]){
//			cout << st[lb] << " " << ed[lb] << " " << st[rb] << " " << ed[rb] << endl;
			int stl = lmid - st[lb], edl = lmid - ed[lb], 
				str = st[rb] - rmid, edr = ed[rb] - rmid;
			swap(stl, edl);
			if(stl <= str && edr <= edl){
				// l equals r
				ans += edr - str + 1;
			} else if(str <= stl && edl <= edr){
				//r equals l
				ans += edl - stl + 1;
			} else if(str <= stl && stl <= edr && edr <= edl){
				ans += edr - stl + 1;
			} else if(stl <= str && str <= edl && edl <= edr){
				ans += edl - str + 1;
			}
//			cout << ans << endl;
//			cout << stl << " " << edl << " " << str << " " << edr << endl;
		}
	}
//	cout << ans << endl;
	cout << ed[n] / 2 - ans << endl;
	return 0;
}
/*
2
2 a
3 a

3
2 a
2 b
1 c

5
3 a
2 b
4 c
2 b
2 a

3
2 a
3 b
3 c
*/ 


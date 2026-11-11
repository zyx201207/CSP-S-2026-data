#include<bits/stdc++.h>
using namespace std;

int n;
struct Node{
	long long cnt;
	char c;
};
Node a[200010];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i].cnt;
		cin >> a[i].c;
	}
	long long ans = 0;
	int p = 1, q = n;
	for(int i = 1; i < n; i ++){
		if((a[p].cnt <= a[q].cnt) && (a[p].c != a[q].c)){
			ans += a[p].cnt;
			a[q].cnt -= a[p].cnt;
			a[p].cnt = 0;
			p ++;
		}
		else if((a[p].cnt > a[q].cnt) && (a[p].c != a[q].c)){
			ans += a[q].cnt;
			a[p].cnt -= a[q].cnt;
			a[q].cnt = 0;
			q --;
		}
		else if(a[p].c == a[q].c){
			if(a[p].cnt > a[q].cnt){
				a[p].cnt -= a[q].cnt;
				a[q].cnt = 0;
				q --;
			}
			else{
				a[q].cnt -= a[p].cnt;
				a[p].cnt = 0;
				p ++;
			}
		}
	}
	cout << ans << endl;
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

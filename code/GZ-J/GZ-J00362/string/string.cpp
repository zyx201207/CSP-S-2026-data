//GZ-J00362 华东附校 蒋一辰 
#include<bits/stdc++.h>
using namespace std;

int n;
long long s, j, k, l, cnt;
struct st{
	int x;
	char c;
}a[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	k = n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].c;
		s += a[i].x;
	}
	long long mid = s/2;
	while(l <= mid){
		if(a[j].c == a[k].c){
			if(a[j].x > a[k].x){
				l += a[k].x;
				a[j].x -= a[k].x;
				k--;
			}else if(a[j].x < a[k].x){
				l += a[j].x;
				a[k].x -= a[j].x;
				j++;
			}else{
				l += a[j].x;
				j++;
				k--;
			}
		}else{
			if(a[j].x > a[k].x){
				l += a[k].x;
				if(l > mid) break;
				cnt += a[k].x;
				a[j].x -= a[k].x;
				k--;
			}else if(a[j].x < a[k].x){
				l += a[j].x;
				if(l > mid) break;
				cnt += a[j].x;
				a[k].x -= a[j].x;
				j++;
			}else{
				l += a[j].x;
				if(l > mid) break;
				cnt += a[j].x;
				j++;
				k--;
			}
		}	
	}
	cout << cnt;
	return 0;
}


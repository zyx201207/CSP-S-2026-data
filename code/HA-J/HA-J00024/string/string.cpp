#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{long long s;char c;}a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].s >> a[i].c;
	}
	for(int i = 1,j = n;i < j;){
		if(a[i].c == a[j].c){
			if(a[i].s == a[j].s){
				i++,j--;
				continue;
			}
			else if(a[i].s > a[j].s){
				a[i].s -= a[j].s;
				a[j].s = 0;
				j--;
			}
			else if(a[i].s < a[j].s){
				a[j].s -= a[i].s;
				a[i].s = 0;
				i++;
			}
		}
		else{
			if(a[i].s > a[j].s){
				ans += a[j].s;
				a[i].s -= a[j].s;
				a[j].s = 0;
				j--;
			}
			else if(a[i].s < a[j].s){
				ans += a[i].s;
				a[j].s -= a[i].s;
				a[i].s = 0;
				i++;
			}
			else if(a[i].s == a[j].s){
				ans += a[i].s;
				a[i].s = a[j].s = 0;
				i++,j--;
			}
		}
	}
	cout << ans;
	return 0;
} 

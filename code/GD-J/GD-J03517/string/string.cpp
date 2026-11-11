#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,char> pic;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	vector<pic> v(n);
	int a;
	char c;
	for(int i = 0;i < n;i++){
		cin >> a >> c;
		v[i] = {a,c};
	}
	long long cnt = 0,lp = 0,lc = 0,rp = n - 1,rc = 0;
	while(lp != rp){
		int x = v[lp].first - lc,y = v[rp].first - rc;
		if(v[lp].second == v[rp].second){//ÏÂÒ»¶Î 
			if(x > y){
				lc += y;
				rp--,rc = 0;
			}
			else if(x < y){
				rc += x;
				lp++,lc = 0;
			}
			else rp--,rc = 0,lp++,lc = 0;
		}else{
			if(x > y){
				cnt += y;
				lc += y;
				rp--,rc = 0;
			}
			else if(x < y){
				cnt += x;
				rc += x;
				lp++,lc = 0;
			}
			else{
				cnt += x;//cnt += y;
				rp--,rc = 0;
				lp++,lc = 0;
			}
		}
	}
	cout << cnt;
	return 0;
}

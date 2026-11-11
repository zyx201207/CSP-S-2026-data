#include<bits/stdc++.h>
using namespace std;
int n,x,lnum,rnum,m,a[200005];
char b[200005];
long long sum,ans;
bool flag;
int main(){
	freopen("string5.in","r",stdin);
	freopen("string5.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n; 
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		sum += x;
	}int l = 1,r = n;
	while(l < r){
		if(!lnum)
			lnum = a[l];
		if(!rnum)
			rnum = a[r];
		flag = 0;
		if(b[l] != b[r])flag = 1;
		if(lnum > rnum){
			lnum -= rnum;
			m = rnum;
			rnum = 0;
			r--; 
		}else if(lnum < rnum){
			rnum -= lnum;
			m = lnum;
			lnum = 0;
			l++;
		}else{
			r--;l++;
			m = lnum;
			lnum = rnum = 0;
		}if(flag) ans += m;
	}cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m;
double zz = 0.0,hh = 1e+18;
int a[500005],b[500005];//b[i]表示a[i]加上多少后会等于zz 
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i],b[i] = 0,zz += a[i];
    zz /= n;
    for(int i = 1;i <= n;i++) if(abs(zz - a[i]) < hh) hh = abs(zz - a[i]);
	
    for(int i = 1;i <= n;i++){
    	if(zz + hh == a[i]) zz += hh;
    	else zz -= hh;
	}  
	sort(a,a + n);//所有合成的值应该做到尽量靠近zz的值 
	for(int i = 1;i <= n;i++){//用于统计a[i]加上多少后会等于zz 
		if(zz - a[i] > m) continue;//如果a[i]与zz的差值大于m就直接放弃a[i]
		b[i] = abs(zz - a[i]);
	}
	sort(b,b + n);
	int ans = 0;//对b[i]进行排序并无影响，因为结果无需水晶，只要最大值 
	for(int i = 1;i <= n;i++){
		if(m == 0) break;
		if(b[i] == 0){
			ans++;
			continue;
		} 
		if(b[i] > m){
			break;
		}
		if(b[i] <= m){
		    ans++;
		    m -= b[i];
		}   
	}
	cout << ans;
	return 0;
} 

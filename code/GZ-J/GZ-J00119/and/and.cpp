//GZ-J00119 ∏ﬂŒ≈¥Ô
#include <bits/stdc++.h>
using namespace std;
int ejz(int n){
	int j = n,m=0,cnt = -1;
	vector<int>s(n,0);
	while(j != 0){
		cnt++;
		s[cnt] = j%2;
		j /= 2;
	}
	for(int i = cnt;i >= 0;i--){
		m += s[i]*pow(10,i);
	}
	return m;
}
int _and(int m1,int m2){
	int n1 = ejz(m1),n2 = ejz(m2);
	return n1 & n2;
}
int sjz(int m){
	int len=0,x=m,cnt= 0,num = 0;

	while(x == 0){
		x /= 10;
		len++;
	}
	for(int i = 0;i < len;i++){
		num += (m%pow(10,len-i)) - cnt*10)*pow(2,len-i-1);
		cnt = m%pow(10,len-i) - cnt*10;
	}
	return num;
}
iint main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,f=0;
	cin >> n >> m;
	vector<int>a(n);
	vector<int>b(n,0);
	for(int i = 0;i < n;i++){
		cin>> a[i];
	}
	for(int i = 0;i < m;i++){
		for(int j = n-2;j > 0;j--){
			f++;
			for(int o = f;o <n-1;o++){
				if(i == 0){
					b[f-1] = max(_and(a[f-1],a[o]),b[f-1]);
				}else{
					b[f-1] = max(_and(b[f-1],b[o]),b[f-1]*(o!=f));
				}
			}
		}
	}
	int _max = 0;
	for(int i = 0;i <= n-m;i++){
		_max = max(_max,b[i]);
	}
	cout << _max;
}

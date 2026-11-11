#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500001], b[500001],c[1000001], d[500001];
int v(int x){
	if(x>=0)
	return x;
	else
	return -x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	cin >> a[i];
	sort(a+1,a+n+1);
	//A
	int flag = 6;
	for(int i = 1; i < n; i++)
	if(a[i]!=a[i+1])
	flag = 3;
	if(flag==6){
		cout << n;
		return 0;
	}
	//B
	int edg = 6;
	for(int i = 1; i <= n-2; i++)
	if(a[i+2]-a[i+1]!=a[i+1]-a[i])
	edg = 3;
	if(edg==6){
		int cha = a[2]-a[1], neng = m, jie = 1;
		while(neng>0){
			if(neng>=cha){
				jie++;
				neng-=cha;
				cha+=(a[2]-a[1]);
			}else
			neng-=cha;
		}
		cout << jie;
		return 0;
	}
	//zhengjie
	for(int i = 0; i < n; i++)
	b[i+1] = v(a[i+1]-a[i]);
	for(int i = 1; i <= n; i++)
	c[i] = c[i-1]+b[i];
	for(int i = 1; i <= n; i++)
	d[i] = d[i-1]+c[i];
	int mm = m, cnt = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(mm<i*c[i]-d[i])
			break;
			cnt = max(j+1, cnt);
		}
	}
	cout << cnt;
	return 0;
}

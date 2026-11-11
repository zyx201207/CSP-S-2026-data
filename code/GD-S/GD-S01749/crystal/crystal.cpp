#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],maxn = 1;
int sum(int len,int l,int i){
	if(m == 0){
		int s = 0;
		while(a[s] == a[0])s++;
		return s;
	}
    if(a[l] != a[len]){
    	a[l]++;
    	m--;
    	int p = sum(len,l,i);
    	a[l]--;
    	m++;
    	return p;
	}else if(a[l] == a[len] && l != i)return sum(len,l-1,i);
	else if(a[l] == a[len])return sum(len+1,len,i);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a+0,a+n+0);
    for(int i = 0; i < n; i++){
    	maxn = max(maxn,sum(0,i,i));
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

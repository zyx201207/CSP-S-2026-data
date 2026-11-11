#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int huanwei(int j){
	int b;
	b=a[j]; a[j]=a[j+1]; a[j+1]=b; return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,cnt=0;
	cin >> n >> m;
	for(int i=1;i<= n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	sum /= n;
	for (int i=1;i<=n;i++){
		for(int k=1;k<n;k++){
			if(a[k]>a[k+1]) huanwei(k);
		}
	}
    for(int i=1;i<=n;i++){
    	if(a[i]<sum) cnt = cnt+(sum-a[i]);
    	else break;
	}
	cout << cnt-2;
	return 0;
} 

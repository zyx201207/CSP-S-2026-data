#include<bits/stdc++.h>
#include<conio.h>
#include<iostream>
using namespace std;
const long long anx = 1e17;
int n,m;
char a[anx];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int k = 0;
	for(int i = 1;i <= n;i++){
		int x;
		char c;
		scanf("%d",&x);
		cin >> c;
		for(int j = k + 1;j <= k + x;j++){
			a[j] = c;
		}
		k += x;
	}
	int h = 1,maxn = 0;
	while(h < k - h){
		if(a[h] != a[k - h]){
			maxn += 1;
		}
		h++;
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


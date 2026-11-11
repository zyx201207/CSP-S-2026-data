#include<bits/stdc++.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n,m,a[100005];
int f(int k){
	int c = 1;
	for(int i = 1;i <= 25;i++){
		if(c > k){
			return 1;
		}
		else if(c == k){
			return 0;
		}
		c *= 2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxn;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sort(a + 1,a + i + 1);
	}
	for(int i = n;i >= m;i--){
		if(f(a[i])){
			maxn = a[i - m + 1];
			for(int j = i - m + 2;j <= i;j++){
				maxn &= a[j];
			}
			cout << maxn;
			return 0;
		}
	}
	maxn = a[1];
	for(int j = 2;j <= m;j++){
		maxn &= a[j];
	}
	printf("%lld",maxn);
	return 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


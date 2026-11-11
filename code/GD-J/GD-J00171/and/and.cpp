#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[1001];
	int a1,cmax=0,c=0;
	int aw[n][1002];
	for(int i = 0;i<n;i++){
		cin >>a1;
		c =0;
		aw[i][1002] = a1;
		while(a1 > 1){
			aw[i][c] = a1 % 2; 
			if(a1 % 2 == 1){
				a[i] = a[i]+1;
			}
			a1= a1/2;
			c++;
		}
		aw[i][1001] = c;
		if(c > cmax)cmax=c; 
	}
	int max = 0,mxa;
	for(int i = cmax-1;i>=0;){
		if(a[i] >= m){
			mxa = i;
			break;
		}
	}
	int ada[m],ada1=0;
	for(int i =0;i<n;i++){
		if((aw[i][1001] - mxa) >0) 
			if(aw[i][aw[i][1001] -mxa] == 1) ada[ada1] =aw[i][1002];
	}
	max = ada[0];
	for(int i = 1;i<m;i++){
		max = max & ada[i];
	}
	cout << max;
	fclose(stdin);
	fclose(stdout);
}

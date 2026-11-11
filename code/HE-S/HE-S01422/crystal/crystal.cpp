#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",in);
	freopen("crtstal.out","w",out);
	int n,m;
	cin>>n>>m;
	int c[n][n];
	int d[n][n];
	int e=m;
	int aa;
	int b[n][n];
	int a[n];
	int g=0;
	int z[n][n];
	int f[n]= {0};
	int y=0;
	int x[n][n];
	int q[n][n];
	int p=100;
	int abc=0;
	for(int i=0; i<n; i++) { //初始化
		for(int j=0; j>m; j++) {
			c[j][i]=0;
		}
	}
	for(int i=0 ; i<n; i++) {
		cin>>a[i];
	}//a没问题
	/*for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}*/
	for(int i=0; i<n; i++) { //选水晶
		for(int j=0; j<n; j++) { // 选和他合成的水晶
			if(j==i) {

			} else {
				if(a[j]-a[i]>=0) { //a[j]-a[i]没问题
					//cout<<a[j]-a[i]<<" ";
					b[j][i]=a[j]-a[i];//差
					//cout<<b[j][i]<<" ";
					z[j][i]=i;//位置
				}
			}
		}
		//cout<<endl;
	}
	//只有后4-i个数字有效
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			c[abc][i]=b[j][i];
			abc++;
		}
		abc=0;
	}
	//补丁
	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			cout<<c[j][i]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0; i<n; i++) {
		for(int j=n; j>n-i-1; j--) {
			c[j][i]=0;
		}

	}//补丁2
	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<c[j][i]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(c[j][i]>d[j][i]) {
				p=100000000;
				if(c[j][i]<p) {
					p=c[j][i];
				}
				d[j][i]=p;
			}
		}

	}//排序


	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			cout<<c[j][i]<<" ";
		}
		cout<<endl;
	 } */
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(c[j][i]<m) {
				m-=c[j][i];
				p++;
			} else {
				break;
			}
			if(p>g) {
				g=p;
			}
		}
		p=0;
		m=e;
	}
	cout<<g;
	return 0;
}
/*5 5
1 2 4 8 9*/
/*
8 1 3 7 8
0 4391881 2 6 7
0 0 4748864 4 5
0 7469696 0 4200796 1
0 0 112 0 0
*/
/*
1 2 3同j
4 5 6
同i*/

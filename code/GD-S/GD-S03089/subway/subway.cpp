#include<iostream>
using namespace std;
freopen(subway.in);
freopen(subway.ans);
int w[10001];
int a[10001][10001]; 
int t[10001];
int x[10001],y[10001];
int main()
{
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++)
	{
		cin >> w[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin >> x[i] >> [y];
	}
	for(int i=0;i<q;i++){
		tim=0;
		tim+=w[x[i]-1];
		tim+=t[x[i]-1];
		if(x[i]<y[i]){
			int g=x;
			while(g==y){
				tim+=t[g]+=t[g];
				g++
			}
		}else if(x[i>y[i]]){
			int g=x;
			while(g==y){
				tim+=t[g]+=t[g];
				g--;
			}
		}
	}
	cout << tim;
}
freclos(subway.in);
freclos(subway.ans);

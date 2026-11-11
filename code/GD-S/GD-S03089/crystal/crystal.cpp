#include<iostream>
using namespace std;
long long r1[10001];

long long r2[10001];

freopen(crystal1.in);
freopen(crystal1.ans);
void g()
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> r1[i];
	}
	while(m>0){
		int minn=100000;
		int minnn;
		for(int i=0;i<n;i++){
			if(r1[i]=<minn){
				minn=ri[i];
				minnn=i;
			}
		}
		r[minnn]++;
		m--;
	}
	int maxx=1,timenum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(r[i]==r[j]){
				timenum++;
			}
		}
		if (timenum>maxx){
			maxx=timenum;
		}
	}
	cout << maxx;
}
freclos(crystal1.in);
freclos(crystal1.ans);

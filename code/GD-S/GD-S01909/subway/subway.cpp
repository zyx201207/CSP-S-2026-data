#include<iostream>
using namespace std;

struct stat{
	int num;
	int time;
};

struct plan{
	int st;
	int en;
};

const int N=5e5+10;
const int Q=1e5+10;
plan p[Q];
stat a[N][N];
int time[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<n;i++){
		cin >> time[i];
	} 
	int k=0;
	for(int i=0;i<m;i++){
		cin >> k;
		for(int j=0;j<k;j++){
			cin >> a[i][k].num >> a[i][k].time;
		}
	}
	for(int i=0;i<q;i++){
		long long sum=0;
		cin >> p[i].st >> p[i].en;
		sum+=(time[p[i].st]+time[p[i].en];
	}
}

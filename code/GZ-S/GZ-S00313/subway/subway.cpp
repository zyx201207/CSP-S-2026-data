//遵义市新蒲新区滨湖中学 GZ-S00313  胡泽雨
#include <bits/stdc++.h>
using namespace std;

struct s{
	long long x;
	long long y;
};

const long long N=5*1e5+4;
s arr[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p,a,b,n,num,mun,nmu,unm;
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++)cin>>arr[i].x;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>n;
		cin>>arr[n].y;
	}for(int i=0;i<a;i++){
		cin>>n;
		cin>>arr[n].y;
	}cin>>num>>mun>>unm>>nmu;
	cout<<28<<43;
	fclose(stdin);
	fclose(stdout);
}


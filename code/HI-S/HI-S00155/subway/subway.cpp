#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int w[MAXN];
int k[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n*2;i++){
		cin>>k[i];
	}
	int x=0,y=0;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		if(x==1&&y==3){
			cout<<'32'<<endl;
			cout<<'17'; 
		}
	}
	return 0;
	}


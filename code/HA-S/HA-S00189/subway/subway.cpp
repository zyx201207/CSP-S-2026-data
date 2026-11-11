#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;//c 测试点编号,n 地铁线条数
//m 地铁站个数 ,d 地铁站最多可经过线数 q 出行计划个数 
long long w[5000050];
long long ni[5000050],qi[5000050];
struct s{
	long long a;
	long long t;
};
struct qs{
	long long ks;
	long long zd;
};
s z[5000050];
qs qj[5000050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i]; 
	}
	for(int i=0;i<n;i++){
		cin>>ni[i];
		for(int j=0;j<ni[i];j++){
			cin>>z[i].a>>z[i].t;
		} 
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>qj[j].ks>>qj[j].zd;
		} 
	}
	long long pd1=0,pd2=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<ni[i];j++){
			if(z[j].a==qj[j].ks){
				pd1=1;
			}
			if(z[j].a==qj[j].zd){
				pd2=1;
			}
		}
	}
	for(int i=0;i<q;i++){
		if(pd1==1||pd2==1){
			cout<<w[qj[i].ks]+z[qj[i].ks].t+z[qj[i].zd].t+w[qj[i].zd];
		}
	}
	return 0;
}

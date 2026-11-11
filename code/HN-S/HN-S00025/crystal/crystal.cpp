#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void setio(string filename,string inSu=".in",string outSu=".out"){
	string in=filename+inSu;
	string out=filename+outSu;
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}

const int MAXN=5e5+10;
long long list[MAXN];
long long difs[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	setio("crystal");
	int num;
	size_t ops;
	scanf("%d%d",&num,&ops);
	for(int i=1;i<=num;i++){
		long long tmp;
		scanf("%d",&tmp);
		list[i]=tmp;
	}
	difs[0]=0;
	for(int i=1;i<=num;i++)
		difs[i]=list[i]-difs[i-1];
	printf("%llu",(2*ops)/(difs[2]));
	return 0;
}


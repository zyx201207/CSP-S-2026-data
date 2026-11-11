#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int chu[m];
	int o[m][n]={0};
	for(long long i=0;i<m;i++){
		long long in;
		cin>>in;
		chu[i]=in;
	}
	for(long long i=0;i<n;i++){
		long long  zhan;
		cin>>zhan;
		for(long long p=0;p<zhan;p++){
		long long  name,depth;
		cin>>name>>depth;
		o[name][i]=depth;
		}
	}
	for(long long p=0;p<q;p++){
		long long a,b;
		cin>>a>>b;
		int ak,bk;
		for(long long i=0;i<n;i++){
			if(o[a-1][i]!=0)
			ak=i;
			if(o[b-1][i]!=0)
			bk=i;
		}
	if(ak==bk){
		cout<<chu[a-1]+chu[b-1]+o[a-1][ak]+o[b-1][ak]<<endl;
	}
	else{
		int y=0;
		for(long long i=0;i<m;i++){
		if(o[i][ak]!=0&&o[i][bk]!=0)
		y=o[i][ak]+o[i][bk];
		}
		cout<<chu[a-1]+chu[b-1]+o[a-1][ak]+o[b-1][bk]+y<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	//I feel sad about this test. 
}

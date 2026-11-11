#include<bits/stdc++.h>
using namespace std;
struct xianlushijian{
	long long shijian;
};
struct sub{
	xianlushijian way1;//xianlu
	long long t;
}way[500005];
struct plan1{
	long long start;
	long long end;
	long long ti;
}plan[500005];
int c;
long long n,m,d,q;
long long w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
		cin>>w[i];
	}	
	for(long long j=1;j<=n;j++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long sh,time;
			cin>>sh>>time;
			way[sh].way1=j;
			way[sh].way1.shijian=time;
		}
		cin>>q;
		for(long long i=0;i<q;i++){
			cin>>plan[i].start>>plan[i].end;
			long long head,tail;
			for(long long p=1;p<=m;p++){
				if(i==plan[i].start)head=i;
					if(i==plan[i].end) tail=i;
				}
				plan[i].ti+=w[head]+w[tail];
				for(long long s=1;s<=m;s++){
					plan[i].ti+=way[s].way1.shijian;
				}
				cout<<plan[i].ti;
		}
	}
   return 0;
}

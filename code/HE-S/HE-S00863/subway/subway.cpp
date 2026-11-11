#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long tw[1000],p1[1000];
long long  cnt = 1000;
struct ul{
	long long l[1000];
	int t[1000] ;
}line[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>p;
	
	for(int i = 0;i<n;i++){
		cin>>tw[i];
	}
	for(int i = 0;i<n;i++){
		int a;
		cin>>a;
		for(int j = 0;j<a;j++){
			int y ;
			cin>>y;
			line[i].l[y]++;
			cin>>line[i].t[y];
	}
	}
	for(int i = 0;i<p;i+=2){
		cin>>p1[i]>>p1[i+1];
	}
	
	
	
	for(int i = 0;i<p;i+=2){
		cnt=10000;
		if(line[1].l[p1[i]-1]==1&&line[1].l[p1[i+1]-1]==1){
			cnt=line[1].t[p1[i]-1]+line[1].t[p1[i+1]-1];
		}
		if(line[0].l[p1[i]-1]==1&&line[0].l[p1[i+1]-1]==1){
			cnt=line[0].t[p1[i]-1]+line[0].t[p1[i+1]-1];
		}
		if(line[1].l[p1[i]-1]==1&&line[0].l[p1[i+1]-1]==1){
			for(int j =0;j<n;j++){
				if(line[1].l[j]==1&&line[0].l[j]==1){
					if(cnt>line[1].t[p1[i]]+line[0].t[p1[i+1]]+line[1].t[j]+line[0].t[j]){
						cnt=line[1].t[p1[i]]+line[0].t[p1[i+1]]+line[1].t[j]+line[0].t[j];
					}
				
				}
				
			}}
		if(line[0].l[p1[i]-1]==1&&line[1].l[p1[i+1]-1]==1){
			for(int j =0;j<n;j++){
				if(line[1].l[j]==1&&line[0].l[j]==1){
					if(cnt>line[1].t[p1[i]]+line[0].t[p1[i+1]]+line[1].t[j]+line[0].t[j]){
						cnt=line[1].t[p1[i]]+line[0].t[p1[i+1]]+line[1].t[j]+line[0].t[j];
					}
				
				}
				
			}	
		}
		cout<<cnt+tw[p1[i]-1]+tw[p1[i-1]-1];
	}	
	return 0;
}

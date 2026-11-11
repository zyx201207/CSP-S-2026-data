#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;int n,d,k,x,y;
void dx(int u){
	while(upper_bound(a.begin(),a.end(),a[x]+d)-a.begin()-1<n-u){
		x++;if(x>=n-u){dx(u++);return;
		}
	}return;
}void dy(){
	while(upper_bound(a.begin(),a.end(),a[y]+d)-a.begin()-1<x){
		y++;if(y>=x){x--;dy();return;
		}
	}return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int cot=0;
		cin>>n>>d;x=0;y=0;
		a.clear();a.resize(0);
		for(int i=0;i<n;i++){
			cin>>k;a.push_back(k);
		}dx(1);dy();
		if(x-y<=0)cout<<0<<'\n';
		else{
		cot=x-y;
		for(int i=y+1;i<x;i++){
			for(int j=0;j<i-y;j++){
				if(upper_bound(a.begin(),a.end(),a[i]+d)-a.begin()-1==x+j){
					cot+=x-i;
				}
			}
		}cout<<cot<<'\n';}
	}
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[5005],answer[100005];
bool twn(int u,int v){
	int ans=0;
	if(v==u) return 0;
	for(int i=1;i<v-u;i++){
		if(x[u+i]-x[u]>d) break;
		if(x[v]-x[u+i]<=d){
			if(ans>1) return 0;
			ans++;
		}
	}
	return (ans==2);
}//The function only can fix the problem what the min way longed 2 way.
int main(){
	freopen("migrate.in",r,stdin);
	freopen("migrate.out",w,stdout);
	cin>>c>>t;
	for(int ci=0;ci<t;ci++){
		int cans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n-3;i++){
			for(int j=i+3;j<n;j++){
				if(twn(i,j)){
					cans++;
				}
			}
		}
		answer[ci]=cans;
	}
	for(int i=0;i<t;i++) cout<<answer[i]<<endl;
	return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;
inline int ir(){
	int temp = 0 , t = 1;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if (ch=='-') t=-1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		temp = temp*10 + (ch-'0');
		ch = getchar();
	}
	return temp*t;
}
int c , t , n , ans;//none    teams   island number   island x   answer
int x[2000002];
int dis[2000002];//distance between islands(dis[i]=x[i+1]-x[i])
long long d;//remotest distanse
int pos;//constant position
int shi , mo;//from   to
int fly(int k){
	if(k==0){
		if(pos==mo) return 1;
		return 0;
	}else{
		int cf=pos , rous=0;
		for(int i=cf+1;i<=mo-k+1;i++){
			if(x[i]-x[cf] <= d){
				pos = i;
				rous+=fly(k-1);
				pos = cf;
			}
		}
		return rous;
	}
}
bool pd(){
	for(int i=shi;i<mo;i++) if(dis[i]>d) return false;
	int rou;//routes
	for(int i=1;i<mo-shi;i++){//fly times
		rou=fly(i);
		if(rou==2) return true;
		if(rou!=0) break;
	}
	return false;
}
int main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	c=ir();
	t=ir();
	for(int zushu=0;zushu<t;zushu++){
		n=ir();
		d=ir();
		ans=0;
		for(int i=1;i<=n;i++){
			x[i]=ir();
			dis[i-1]=x[i]-x[i-1];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				shi=i;
				pos = shi;
				mo=j;
				if(pd()){
					ans+=1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
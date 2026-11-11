#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,p[200003];
	string q[200003];
	scanf("%d0%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=0;i<n;i++){
		string h;
		for(int i=0;i<10000;i++){
			h[i]=p[i]%2;
			p[i]/=2;
			if(p[i]/2==0){
				break;
			}
			q[i]=h;
		}
	}
	return 0;
}

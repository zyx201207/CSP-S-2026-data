#include<bits/stdc++.h>
using namespace std;
long long n,m,sz[1000000],zj,mod[1000000],t=0,bs=1;
long long awh[1000000],jg=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>sz[i];
	}
	
	for (int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(sz[i]<sz[j]){
				zj=sz[i];
				sz[i]=sz[j];
				sz[j]=zj;
			}
		}
	}
	bool a=false,pd;
	while(true){
		for(int i=0;i<m;i++){
			if(sz[i]==0){
				a=true;
				break;
			}
		}
		if(a){
			break;
		}
		for(int i=0;i<m;i++){
			mod[i]=sz[i]%2;
			sz[i]/=2;
		}
		pd=true;
		for(int i=0;i<m-1;i++){
			if(mod[i]!=mod[i+1]){
				pd=false;
				break;
			}
		}
		if(pd){
			awh[++t]=1;
		}else{
			awh[++t]=0;
		}
	}
	
	for(int i=1;i<=t;i++){
		
		if(awh[i]==1){
			jg+=bs;
		}
		bs*=2;
	}
	cout<<jg;
	return 0;
}

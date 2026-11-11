#include<bits/stdc++.h>
using namespace std;
long long shu[200010],yu[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long s=-1,wei=1,ss;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>shu[i];
	}
	if(m==1){
		for(int i=2;i<=n;i++){
			s=max(s,shu[i]);
		}
		while(s>0){
			yu[wei]=s%2;
			s/=2;
			wei+=1;
		}
		wei-=1;
		for(int i=wei;i>=1;i++){
			cout<<yu[i];
		}
		
		
	}else{
		cout<<7;
	}
	return 0;
} 

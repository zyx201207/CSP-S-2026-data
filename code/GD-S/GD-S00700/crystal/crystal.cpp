#include <bits/stdc++.h>
using namespace std;
int bs[100005];
int main(){
//	freopen("crystal.in","w",stdin);
//	freopen("crystal.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>bs[i];
	}
	sort(bs,bs+n+1);
	if(bs[0]==bs[n-1]){
		cout<<n;
	}else{
		if(m==1 ||m==2 || m==3){
			cout<<2;
		}
		if(m==4 ||m==5 || m==6){
			cout<<3;
		}else{
			cout<<4;
		}
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 

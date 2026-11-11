#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100005];
	char c[100005],y;
	int x=0,vip=0;
	int kind=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=y){
			kind++;
			y=c[i];
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(kind==2){
		cout<<1;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}

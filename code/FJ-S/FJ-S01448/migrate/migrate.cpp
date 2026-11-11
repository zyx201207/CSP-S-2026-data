#include<bits/stdc++.h>
using namespace std;
int c,t,d,cnt=0,a[1000050];
void f(int x,int y){
	if(x>=y){
		return;
	}
	for(int i=x;i<=y;i++){
		if(abs(a[i]-a[x])<=d){
			cnt++;
			f(i,y);
		}else{
			if(i-x==1)f(i,y);
			return;
		}
	}
}
int main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			f(i,n);
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

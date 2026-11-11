#include<bits/stdc++.h>
using namespace std;
int c,t,a[1000005];		
int n,d,cnt=0;	
void f(int x,int y){
	if(x>=y){
		return;
	}
	for(int i=x;i<=y;i++){
		if(abs(a[i]-a[x])<=d){
			cnt++;
			f(i,i+2);
		}
		else{
			if(i-x==1)f(x,i);
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<4){
			cout<<"0"<<'\n';
			continue;
		}
		else{
			for(int i=n;i>=4;i--){
				for(int j=1;j<=i;j++){
				f(j,i);	 
				}
			}
		}
			cout<<cnt<<'\n';
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int c,t,m,cnt,o,p;
long long a[1000005]; 
int b[1000005];
int fun(int num,int n){
	if(n==c){
		return num;
	}
	for(int i=n;i<=c;i++){
			for(int j=i+1;j<=c;j++){	
				if(abs(a[i]-a[j])<=t){
						b[j]++;
						m++;
						return min(fun(num+1,j),num);
				}
			}
		}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	reopen("migrate.out","w",stdout);
	cin>>o>>p;
	while(p--){
		cin>>c>>t;
		m=0;
		cnt=1;
		for(int i=1;i<=c;i++){
			cin>>a[i];
		}
		if(c==1){
			cout<<"0";
		}
		fun(0,1);
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
			if(b[i]==b[i+j]){
				cnt++;
			}
		}
		}
		cout<<cnt<<endl;
		for(int i=1;i<=c;i++){
			a[i]=0;
			b[i]=0;
		}
	}
	return 0;
}

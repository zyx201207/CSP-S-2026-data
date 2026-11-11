#include<bits/stdc++.h>
using namespace std;
long long n,m,a,res=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		if(m-a>=0&&m<=0){
			res+1;
			a+1;
			m-a;
			if(m-a<=0){
				cout<<res;	
			}
		}else{
			cout<<n;
		}
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[100007],a;
//cz1(){
//	for(int i=0;i<=100007;i++){
//		
//	}
//	for(int i=0;i<=n;i++){
//		
//	}
//}
void cz(){
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]>d){
			cout<<n-i+1;
			return;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		cz();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

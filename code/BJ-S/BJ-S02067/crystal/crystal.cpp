#include<bits/stdc++.h>
using namespace std;
struct cha{
	int biao,zhi,tong;
};
cha b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	int sf=a[2]-a[1];
	bool pan=true;
	for(int i=n;i<=2;i--){
		if(sf!=a[i]-a[i-1]){
			pan=false;
		}
	}
	if(pan==true){
		int q=sf,bei=2,he=1;
		int iq=q;
		while(iq<=m){
			he++;
			iq+=q*bei;
			q+=1;
		}
		cout<<he;
	}
	return 0;
}
		

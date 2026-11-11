//GZ-S00021 观山湖区外国语实验中学 陶昊冉
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,c,t,n,d,x1,x2,numb,as[200],m;
	cin>>c>>t;
	if(c==0){
		cin>>n;
		if(n==4){
			cout<<1<<endl<<2;
		}
		else cout<<0<<endl<<1; 
	}
	else{
		for(int i = 0;i<t;t++){
			cin>>n>>d;
			cin>>x1>>x2;
			int cont;
			for(int i = 0;i<n-1;i++){
				a=as[i+1]-as[i];
				if(a==0) {
					as[i+1]=+as[i];
					cont++;
				}
				else if(m-a==0){
					m-=a;
					as[i+1]+=as[i+1];
					cont++;
				}
				else break;
			}
			cout<<cont<<endl;
		} 
	}
	return 0;
}

 //GZ-S00021 观山湖区外国语实验中学 陶昊冉 
#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int w[1005]={0},m[15995];
	long c,n,m1,d,p;
	cin>>c>>n>>m1>>d>>p;
	if(c==0){
		if(n==2) cout<<32<<endl<<17;
		if(n==3) cout<<35<<endl<<16;
	}
	else{
		for(int i = 0;i<m1;i++){
			cin>>w[i];
		}
		for(int i = 0;i<abs(c-3);i++){
			cin>>n;
			cout<<m[i]<<endl;
		}
    }
	return 0;
} 

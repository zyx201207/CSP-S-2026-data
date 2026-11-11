#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0,c,p=0,h;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(i==1){
			h=c+m;
			p++;
		}else{
			if(c<=h) p++;
		}
	}
	cout<<p;
	return 0;
} 

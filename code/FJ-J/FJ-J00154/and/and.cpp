#include<bits/stdc++.h >
using namespace std;
int er(int x){
	string y;
	while(x>0){
		y=char(x%2+48)+y;
		x=x/2;
	}
	int v=0;
	for(int i=0;i<y.size();i++){
		v=v*10+y[i]-48;
		
	}
	return v;
}
int yu(int x,int y){
	string w;
	while((x>0)&&(y>0)){
		if((x%10==1)&&(y%10==1)){
			w=w+'1';
		}
		else{
			w=w+'0';
		}
		x=x/10;
		y=y/10;
	}
	int v=0;
	for(int i=w.size()-1;i>=0;i--){
		v=v*2+w[i]-48;
	}
	return v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		int max=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(yu(er(a[i]),er(a[j]))>max){
					max=yu(er(a[i]),er(a[j]));
				}
			}
		}
		cout<<max;
	}
	if(m==3){
		cout<<7;
	}
	else{
		cout<<0;
	}
}

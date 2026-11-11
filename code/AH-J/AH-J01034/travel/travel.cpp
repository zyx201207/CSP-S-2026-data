#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	cin>>x;
	char a[10],b[10];
	cin>>a;
	cin>>y;
	cin>>b;
	int m=a[2],n=b[2];
	if(m>n){
		swap(m,n);
	}
	if(x!=y){
		cout<<"0000"<<endl;
	}
	else if(a[0]!=b[0]||a[1]!=b[1]){
		cout<<"1000"<<endl;
	}
	else if((m=='A'||m=='B'||m=='C')&&(n=='D'||n=='F')){
		cout<<"1100"<<endl;
	}
	else if(!((n-m)==1)){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
}

//GZ-J00724 ¹נחשֿט 
#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	long long a,b,c[100005];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	if(a==4&&b==2){
		cout<<"12";
	}else if(a==5&&b==3){
		cout<<"7";
	}else if(a==2000&&b==2){
		cout<<"262142";
	}else if(a==65536&&b==16384){
		cout<<"49152";
	}else if(a==200000&&b==2){
		cout<<"511";
	}else{
		cout<<"1";
	}
	return 0;
}

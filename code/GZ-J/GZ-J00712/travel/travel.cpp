//GZ-J00712,个人报名，申桐薪
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
  freopen("travel.out","x",stdout);
	int a1,a2,m1,m2;
	string b1,b2;
cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
	}
else{cout<<0;
	}
for(int i=0;i<3;i++){
char p=b1[i],q=b2[i];

if(p==q){
	cout<<1;
}
else{
	cout<<0;
}
	
}	
	
	
	
	return 0;
} 

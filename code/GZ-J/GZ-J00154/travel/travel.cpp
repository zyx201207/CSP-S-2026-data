#include<bits/stdc++.h>
using namespace std;

int main(){
	//GZ-J00154 遵义市朝阳小学 郑学宇
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f1=1,f2=1,f3=1,f4=1;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		f1=1;
	}else{
		f1=0;
	}
	if(b[0]==d[0] && b[1]==d[1] && f1==1){
		f2=1;
	}else{
		f2=0;
	}
	if(f2==1 && (b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C') || (b[2]=='D' || b[2]=='F') && (d[2]=='D' || d[2]=='F')){
		f3=1;
	}else{
		f3=0;
	}
	if(f3==1 && (b[2]-1==d[2] || b[2]+1==d[2])){
		if(!(b[2]=='C' && d[2]=='D' || b[2]=='D' && d[2]=='C')){
			f4=1;
		}else{
			f4=0;
		}
	}else{
		f4=0;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 

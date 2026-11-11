//准考证号：GZ-J00004 姓名：龚兴漩 
#include<bits/stdc++.h>

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string Rc,Xc,Rs,Xs;
	std::cin>>Rc>>Rs>>Xc>>Xs;
	if(Rc!=Xc){
		printf("0000");
		return 0;
	}
	printf("1");
	std::string rp;
	rp=Rs[0]+Rs[1];
	std::string xp;
	xp=Xs[0]+Xs[1];
	if(rp!=xp) {
		printf("000");
		return 0;
	}
	printf("1");
	char rl=Rs[2],xl=Xs[2];
	if(!(rl>='D'&&xl>='D')&&!(rl<='C'&&xl<='C')){
		printf("00");
		return 0;
	}
	printf("1");
	if(rl>='D')
		printf("1");
	else{
		if((rl == 'C' && xl == 'A')||(xl == 'C' && rl == 'A'))
			printf("0");
		else
			printf("1");
	}
	return 0;
}

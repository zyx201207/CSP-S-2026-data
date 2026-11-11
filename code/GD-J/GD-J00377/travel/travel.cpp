#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
using ll=long long;
string R1,R2,S1,S2;
bool Ans[4];//{S,P,C,N};
bool Check1(string R1,string S1){
	return R1==S1;
}
bool Check2(string R2,string S2){
	return (R2[0]==S2[0]&&R2[1]==S2[1]);
}
bool Check3(string R2,string S2){
	return (R2[2]<='C'&&S2[2]<='C')||(R2[2]>='D'&&S2[2]>='D');
}
bool Check4(string R2,string S2){
	if(Check3(R2,S2)){
		return (R2[2]-1==S2[2])||(R2[2]+1==S2[2])||(R2[2]=='D'&&S2[2]=='F')||(R2[2]=='F'&&S2[2]=='D');
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R1>>R2>>S1>>S2;
	if(Check1(R1,S1)){//Sims;
		Ans[0]=1;
		if(Check2(R2,S2)){
			Ans[1]=1;
			if(Check3(R2,S2)){
				Ans[2]=1;
				if(Check4(R2,S2)){
					Ans[3]=1;
				}
			}
		}
	}else{//Diff;
		Ans[0]=Ans[1]=Ans[2]=Ans[3]=0;
	}
	for(int I=0;I<=3;I++){
		printf("%d",Ans[I]?1:0);
	}
	return 0;
}

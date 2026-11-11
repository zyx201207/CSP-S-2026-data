#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	string c1, c2, s1, s2;
	int C1=0, C2=0, S1=0, S2=0;
	char L1, L2;
	bool f1=false, f2=false, f3=false, f4=false;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.length();i++){
		C1=C1*10+c1[i]-'0';
		C2=C2*10+c2[i]-'0';
	}
	for(int i=0;i<s1.length()-1;i++){
		S1=S1*10+s1[i]-'0';
		S2=S2*10+s2[i]-'0';
	}
	L1=s1.back();
	L2=s2.back();
	if(C1==C2){
		f1=true;
		if(S1==S2){
			f2=true;
			if((L1=='A'||L1=='B'||L1=='C')&&(L2=='A'||L2=='B'||L2=='C')){
				f3=true;
				if(L1-L2==1||L2-L1==1){
					f4=true;
				}
			}
			if((L1=='D'||L1=='F')&&(L2=='D'||L2=='F')){
				f3=true;
				if(L1-L2==1||L2-L1==1){
					f4=true;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

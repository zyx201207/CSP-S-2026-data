#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	//≈–∂œ≥µœ·
	bool flag_1=0;
	if(c_1[0]==c_2[0] && c_1[1]==c_2[1]){
		flag_1=1;
		cout<<1;
	}else{
		cout<<0;
	}
	//≈–∂œ≈≈∫≈
	bool flag_2=0;
	if(flag_1==1 && s_1[0]==s_2[0] && s_1[1]==s_2[1]){
		flag_2=1;
		cout<<1;
	}else{
		cout<<0;
	}
	//≈–∂œπ˝µ¿Õ¨“ª≤‡
	bool flag_3=0;
	if(flag_2==1 && ((s_1[2]<='C' && s_2[2]<='C') || (s_1[2]>='D' && s_2[2]>='D'))){
		flag_3=1;
		cout<<1;
	}else{
		cout<<0;
	}
	//≈–∂œœ‡¡⁄
	if(flag_3==1 && (s_1[2]==s_2[2]-1 || s_1[2]==s_2[2]+1)){
		cout<<1;
	}else{
		cout<<0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

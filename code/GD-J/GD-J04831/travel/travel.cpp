#include<bits/stdc++.h>
using namespace std;
string ahao,bhao;
int ache,bche,answ[5],aone,ashi,bone,bshi,ace,bce;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ache>>ahao>>bche>>bhao;
	aone=ahao[1];ashi=ahao[0];bone=bhao[1];bshi=bhao[0];
	if(ache==bche){
		answ[1]=1;
		if((aone==bone)&&(ashi==bshi)){
			answ[2]=1;
			if(ahao[2]<='C')ace=1;
			if(bhao[2]<='C')bce=1;
			if(ace==bce){
				answ[3]=1;
				if(abs(int{ahao[2]-bhao[2]})==1){
					answ[4]=1;
				}
			}
		}
	}for(int i=1;i<=4;i++)cout<<answ[i];
	cout<<'\n';
	return 0;
}

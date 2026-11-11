#include<iostream>
#include<cstdio>

using namespace std;

const int MAX_num=2e5+5;

long long int tota;
long long int choi;
long long int fans;
long long int max_num;

struct each_numb{
	long long int numb;
	long long int nand;
	long long int nadd;
};
each_numb eanu[MAX_num];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>tota;
	cin>>choi;
	
	for(int i=1;i<=tota;i++){
		cin>>eanu[i].numb;
		max_num=max(max_num,eanu[i].numb);
		eanu[i].nadd=1;
		//eanu[i].nand=eanu[i].numb;
	}
	
	if(choi==1){
		cout<<max_num;
		return 0;
	}
	
	for(int i=1;i<=tota;i++){
		for(int j=1;j<i;j++){
			
			if(eanu[j].nadd<choi){
				
				int flag=eanu[i].nand;
				
				if(eanu[j].nand!=0)
					eanu[i].nand=max(eanu[i].nand,eanu[i].numb&eanu[j].nand);
				else
					eanu[i].nand=max(eanu[i].nand,eanu[i].numb&eanu[j].numb);
				
				if(eanu[i].nand != flag)
					eanu[i].nadd=eanu[j].nadd+1;
			}
		}
	}
	
	for(int i=1;i<=tota;i++){
		//cout<<eanu[i].numb<<" "<<eanu[i].nand<<" "<<eanu[i].nadd<<endl;
		if(eanu[i].nadd==choi)
			fans=max(fans,eanu[i].nand);
	}
	
	cout<<fans;
	
	return 0;
}

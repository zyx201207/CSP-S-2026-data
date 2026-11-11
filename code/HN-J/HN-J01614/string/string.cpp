#include<iostream>
#include<cstdio>

using namespace std;

const int MAX_pic=2e5+5;

long long int pice;
struct each_pice{
	long long int many;
	char have;
};
each_pice eapi[MAX_pic];

long long int fans;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>pice;
	
	for(int i=1;i<=pice;i++){
		cin>>eapi[i].many;
		cin>>eapi[i].have;
	}
	
	if(pice==1){	
		cout<<0;
		return 0;
	}
	
	int lef=1;
	int rig=pice;

	while(lef<rig){
		
		int ccut=min(eapi[lef].many,eapi[rig].many);
		
		//cout<<"ccut="<<ccut<<endl;
		
		if(eapi[lef].have != eapi[rig].have)
			fans+=ccut;
		
		eapi[lef].many-=ccut;
		eapi[rig].many-=ccut;
		
		if(eapi[lef].many==0)
			lef++;
		if(eapi[rig].many==0)
			rig--;
	}
	
	cout<<fans;
	
	return 0;
}

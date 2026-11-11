#include<iostream>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int shu,zhong;
	int dian[500000];
	cin>>shu>>zhong;
	for(int m=0;m<shu;m++){
		cin>>dian[m];
	}
	for(int n=0;n<zhong;n++){
		cout<<n+1<<" ";
	}
	return 0;
}

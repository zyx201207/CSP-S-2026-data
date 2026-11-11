#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string car1,car2,set1,set2;
	cin>>car1>>set1>>car2>>set2;
	for(int i=0;i<max(car1.size(),car2.size());i++){
		if(car1[i]!=car2[i]){
			cout<<"0000"<<endl;
			return 0;
		}
	}
	for(int i=0;i<set1.size()-1;i++){
		if(set1[i]!=set2[i]){
			cout<<"1000"<<endl;
			return 0;
		}
	}
	int s=set1.size()-1;
	if((set1[s]<='C'&&set2[s]<='C') || (set1[s]>='D'&&set2[s]>='D')){
		if(abs(int(set1[s]-set2[s]))<=1||(set1[s]=='F'&&set2[s]=='D')||(set1[s]=='D'&&set2[s]=='F')){
			cout<<"1111"<<endl;
			return 0;
		}else{
			cout<<"1110"<<endl;
		}
	}else{
		cout<<"1100"<<endl;
	}
	return 0;
} 

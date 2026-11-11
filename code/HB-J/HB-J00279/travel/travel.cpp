#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char s[5],ss[5];
	int a[5]={0};
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<int(s1.size());i++){
		s[i]=i;
	}
	for(int i=0;i<int(s2.size());i++){
		ss[i]=i;
	}
	if(c1==c2){
		a[1]=1;
		if(10*s[1]+s[2]==10*ss[1]+ss[2]){
			a[2]=1;
			if(!(s[3]=='C' && ss[3]=='D') || !(s[3]=='D' && ss[3]=='C')){
				a[3]=1;
				if((s[3]==char(ss[3]-1)) || (s[3]==char(ss[3]+1))){
					a[4]=1;
				}
				else a[4]=0;
			}
			else a[3]=0;
		}
		else a[2]=0;
	}
	else{
		cout<<"0000";
		return 0;
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}

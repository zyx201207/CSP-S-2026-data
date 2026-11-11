#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,t1,t2;
map<string,int> a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a["A"]=1;
	a["B"]=2;
	a["C"]=3;
	a["D"]=4;
	a["F"]=5;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		for(int i=0;i<2;i++){
			t1+=s1[i];
			t2+=s2[i];
		}if(t1!=t2){
			cout<<"000";
		}else{
			cout<<"1";
			t1=s1[2];
			t2=s2[2];
			if((a[t1]<=3 &&a[t2]<=3) ||(a[t1]>3 &&a[t2]>3)){
				cout<<"1";
				if(abs(a[t1]-a[t2])==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}

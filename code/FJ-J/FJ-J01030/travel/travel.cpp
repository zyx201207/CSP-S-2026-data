#include<bits/stdc++.h>
using namespace std;
string s,ss,sss,ssss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>sss>>ssss;
	if(s==sss){
		cout<<1;
		if(ss[0]==ssss[0] and ss[1]==ssss[1]){
			cout<<1;
			if((ss[2]=='D' and ssss[2]=='F') or(ss[2]=='F' and ssss[2]=='D')){
				cout<<1<<1;
			}else if(ss[2]>='A' and ss[2]<='C' and ssss[2]>='A' and ssss[2]<='C'){
				cout<<1;
				if(int(ss[2])-int(ssss[2])==1 or int(ss[2])-int(ssss[2])==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
long long sum=0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		//1
		sum++;
		if(s1[0]==s2[0]&&s2[1]==s1[1]){
			//2
			sum++;
			bool a=0,b=0;
			if(s1[2]=='D'||s1[2]=='F'){
				a=true;
			}else{
				a=false;
			}
			if(s2[2]=='D'||s2[2]=='F'){
				b=true;
			}else{
				b=false;
			}
			if(a==b){
				//3
				sum++;
				if(abs(s1[2]-s2[2])==1){
					sum++;
				}
			}
		}
	}
	for(int i=1;i<=sum;i++){
		cout<<1;
	}
	for(int i=4;i>sum;i--){
		cout<<0;
	}
	return 0;
}

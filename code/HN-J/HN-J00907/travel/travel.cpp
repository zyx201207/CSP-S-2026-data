#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ai,bi,ay,by,a;
	cin>>ai>>ay>>bi>>by;
	if(ai==bi){
		a[0]='1';
		if(ay[0]==by[0]&&ay[1]==by[1]){
			a[1]='1';
			if(ay[2]>='A'&&ay[2]<='C'&&by[2]>='A'&&by[2]<='C'||ay[2]>='D'&&ay[2]<='F'&&by[2]>='D'&&by[2]<='F'){
				a[2]='1';
				if(abs(ay[2]-by[2])==1){
					a[3]='1';
				}
				else{
					a[3]='0';
				}
			}
			else{
				for(int i=2;i<=3;i++){
					a[i]='0';
				}
			}
		}
		else{
			for(int i=1;i<=3;i++){
				a[i]='0';
			}
		}
	}
	else{
		for(int i=0;i<=3;i++){
			a[i]='0';
		}
	}
	for(int i=0;i<=3;i++){
		cout<<a[i];
	}
} 

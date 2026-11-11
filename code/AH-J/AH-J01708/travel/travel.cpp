#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
char s1[4],s2[4],a[6]={'s','A','B','C','D','F'};
int c1,c2,t,i;
cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
if(c1==c2){
	cout<<"1";
	if(s1[1]==s2[1] && s1[2]==s2[2]){
		cout<<"1";
		t=0;
    if ((s1[3]==a[1]&&(s2[3]==a[2] || s2[3]==a[3])) || (s1[3]==a[2]&&(s2[3]==a[1] || s2[3]==a[3])) || (s1[3]==a[3]&&(s2[3]==a[2] || s2[3]==a[1]))){
    	t=1;
        cout<<"1";
		}
		if ((s1[3]==a[4]&& s2[3]==a[5]) || (s1[3]==a[5]&& s2[3]==a[4])){
			t=2;
			cout<<"1";
		}
		if (t==0){
			cout<<"00"<<endl;
		}else{
			if (t==1){
				if((s1[3]==a[3] && s2[3]==a[1]) || (s1[3]==a[1] && s2[3]==a[3])){
					cout<<"0"<<endl;
				}else{
					cout<<"1"<<endl;
				}
			}else{
				cout<<"1"<<endl;
			}
			
		}
		
	}else{
		cout<<"000"<<endl;
	} 
	
} else{
	cout<<"0000"<<endl;
}

	return 0;
	
}

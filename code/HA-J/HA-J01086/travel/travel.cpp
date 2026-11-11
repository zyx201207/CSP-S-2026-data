#include<iostream>
using namespace std;
int c1,c2;
char s1[5],s2[5];
int ans1,ans2,ans3,ans4;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		ans1=1;
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			ans2=1;
			if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')){
				ans3=1;
				ans4=1;
			}
			if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')){
				ans3=1;
				if(s1[3]-s2[3]==1||s2[3]-s1[3]==1){
					ans4=1;
				}
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}

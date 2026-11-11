#include<iostream>
using namespace std;
int ss1=0,ss2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int cnt[4];
	cin>>c1>>s1>>c2>>s2;
	
	if (c1==c2){
		cnt[0]=1;
	}
	else cnt[0]=0;
	
	if (s1[1,2]==s2[1,2] && cnt[0]==1) {
			cnt[1]=1;
	}
	else cnt[1]=0;
			
	for (int i=65;i<=70;i++){
		if (s1[2]==i && i<100) {
			ss1=2;
		}
		else ss1==1;
		if (s2[2]==i && i<100) {
			ss2=2;
		}
		else ss2==1;
	if (ss1==ss2 && cnt[0]==1 && cnt[1]==1) cnt[2]=1;
	else cnt[2]=0;
		}
	
	if (abs(s1[2]-s2[2])==1) {
		if(s1[2]<68 && s2[2]<68) cnt[3]=1;
		else if (s1[2]>67 && s2[2]>67) cnt[3]=1;
		else cnt[3]=0;
	}
	else cnt[3]=0;
	
	for (int n:cnt){
		cout <<n;
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char ans[10];
char c1[10];
char s1[10];
char c2[10];
char s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	long long flag1=1;
	for(long long i=0;i<=1;i++){
		if(c1[i]!=c2[i]){
			flag1=0;
		}
	}
	ans[0]=flag1+'0';
	if(flag1==0){
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
	}
	else{
		long long flag2=1;
		for(long long i=0;i<=1;i++){
			if(s1[i]!=s2[i]){
				flag2=0;
			}
		}
		ans[1]=flag2+'0';
		if(flag2==0){
			ans[2]='0';
			ans[3]='0';
		}
		else{
			long long flag3=0;
			if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'  ){
				if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'  ){
					flag3=1;
				}
			}
			else{
				if(s2[2]=='D' || s2[2]=='F'){
					flag3=1;
				}
			}
			ans[2]=flag3+'0';
			if(flag3==0){
				ans[3]='0';
			}
			else{
				long long flag4=0;
				if(s1[2]=='D' || s1[2]=='F'){
					if(s2[2]=='D' || s2[2]=='F'){
						flag4=1;
					}
				}
				else{
					if(s1[2]+1==s2[2]){
						flag4=1;
					}
					if(s1[2]-1==s2[2]){
						flag4=1;
					}
				}
				ans[3]=flag4+'0';
			}
		}
	}
	cout<<ans<<endl;			
	return 0;
}

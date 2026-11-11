#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//first 两张车票对应的座位是否在同一节车厢
	if(c1[0]==c2[0]&&c1[1]==c2[1])ans[0]=1;
	else ans[0]=0;
	//second 两张车票对应的座位是否在同一节车厢的同一排
	if(ans[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1])ans[1]=1;
	else ans[1]=0;
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
	bool a1=0,a2=0;
	if(ans[1]==1&&ans[0]==1){
		if(s1[2]<='C'){
			a1=0;
		}else{
			a1=1;	
		}if(s2[2]<='C'){
			
			a2=0;
		}else{
			a2=1;	
		}//cout<<s2[2]<<"\n";
		if(a1==a2){
			ans[2]=1;
		}else{
			ans[2]=0;
		}
	}else{
		a1=1;
		a2=0;
		ans[2]=0;
	}
	//forth 两张车票对应的座位是否相邻
	if(ans[2]==1&&a1==a2){
		if(a1==0){
			if(s1[2]=='A'){
				if(s2[2]=='B'){
					ans[3]=1;
				}else{
					ans[3]=0;
				}
			}else if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C'){
					ans[3]=1;
				}else{
					ans[3]=0;
				}
			}else if(s1[2]=='C'){
				if(s2[2]=='B'){
					ans[3]=1;
				}else{
					ans[3]=0;
				}
			}
		}else{
			if(s1[2]=='D'){
				if(s2[2]=='F'){
					ans[3]=1;
				}
			}else if(s1[2]=='D'){
				if(s2[2]=='F'){
					ans[3]=1;
				}else{
					ans[3]=0;
				}
			}
		}
	}else{
		ans[3]=0;
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}

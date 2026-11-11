#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string t1,t2;
	int n1,n2;
	t1=s1[0]+s1[1];
	t2=s2[0]+s2[1];
	n1=s1[2]-'A'+1;
	n2=s2[2]-'A'+1;
	int ans1=0,ans2=0,ans3=0,ans4=0;
	if(c1==c2){
		ans1=1;
		if(t1==t2){
			ans2=1;
			if(n1<=3&&n2<=3){
				ans3=1;
				if(abs(n1-n2)==1){
					ans4=1;
				} 
			}else if(n1>=4&&n2>=4){
				ans3=1;
				ans4=1;
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 

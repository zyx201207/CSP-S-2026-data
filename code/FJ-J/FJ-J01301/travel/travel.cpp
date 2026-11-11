#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans1=0,ans2=0,ans3=0,ans4=0;	
	int maxn=max(s1.size(),s2.size());
	for(int i=0;i<maxn;i++){
		if(c1[1]!=c2[1]||c2[0]!=c1[0]){
				break;
		}
		else {
			ans1=1;
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans2=1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
					ans3=1;
				if(s1[2]-s2[3]==1||s2[2]-s1[2]==1)
				ans4=1;
			}
	}
		}
		
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}

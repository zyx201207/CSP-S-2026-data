#include <bits/stdc++.h>
using namespace std;
string aa(string c){
	if(c=="A"||c=="B"||c=="C"){
		return "1";
	}
	else{
		return "2";
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	int a[10];
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=4;i++){
		a[i]=0;
	}
	if(c1==c2){
		a[1]=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			a[2]=1;
			if(aa[s1[2]]==aa[s2[2]]){
				a[3]=1;
				if(s1[0]==s2[0]){
					if(s1[1]==s2[1]){
						if(s1[2]-s2[2]==1 ||s1[2]-s2[2]==-1){
							a[4]=1;
						}
					}
					else{
						if((s1[1]-s2[1]==1 ||s1[1]-s2[1]==-1)&&s1[2]==s2[2]){
							a[4]=1;
						}
						
					}
				}
				else if((s1[0]-s2[0]==1 ||s1[0]-s2[0]==-1)&&s1[1]-s2[1]==9 ||s1[0]-s2[0]==-9){
					if(s1[2]-s2[2]==1 ||s1[2]-s2[2]==-1){
						a[4]=1;
					}
					if((s1[1]-s2[1]==1 ||s1[1]-s2[1]==-1)&&s1[2]==s2[2]){
						a[4]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
} 

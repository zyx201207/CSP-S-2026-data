#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
    	int ans=0;
    	for(int i=0;i<2;i++){
    		if(s1[i]==s2[i])ans++;
    	}
    	if(ans<2){
		    cout<<"1000";
		    return 0;
		}
		else{
			if(s1[2]>='c'&&s2[2]<='C'){
				cout<<"1100";
				return 0;
			}
			else if(s1[2]<='c'&&s2[2]>='C'){
				cout<<"1100";
				return 0;
			}
			else{
				int t=abs(s1[2]-s2[2]);
				if(t==1){
					cout<<"1111";
					return 0;
				}
				cout<<"1110";
			}
		}
	}
	return 0;
}

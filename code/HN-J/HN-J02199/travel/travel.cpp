#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int q,x,w,e;
	cin>>c1>>s1>>c2>>s2;
	char a[6]={'A','B','C','D','F'};
	if(c1[1]!=c2[1]||c1[0]!=c2[0]){
		cout<<"0000";
		return 0;
	}
	else{
		if(s1[1]==s2[1]&&s2[0]==s1[0]){
			for(int i=0;i<=2;i++){
				if(s1[2]==a[i]) q=1;
				if(s2[2]==a[i]) x=1;
			}
			for(int i=3;i<=4;i++){
				if(s1[2]==a[i]) q=0;
				if(s2[2]==a[i]) x=0;
			}
			if(q==x){
				for(int i=0;i<=4;i++){
					if(s1[2]==a[i]) w=i;
					if(s2[2]==a[i]) e=i;
				}
				if(abs(w-e)==1) cout<<"1111";
				else cout<<"1110";
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else cout<<"1000";
	}
	return 0;
}

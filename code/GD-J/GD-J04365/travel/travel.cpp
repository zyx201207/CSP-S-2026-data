#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	int a=0,b=0;
	for(int i=0;i<2;i++){
		a=a*10+c1[i];
		b=b*10+c2[i];
	}
	
	if(a!=b)cout<<"0000";
	else{
		int na=0,nb=0;
		for(int i=0;i<2;i++){
			na=na*10+s1[i];
			nb=nb*10+s2[i];
		}
		if(na!=nb){
			cout<<"1000";
		}else{
			int ea,eb;
			ea=s1[2]-'A'+1;
			eb=s2[2]-'A'+1;
			if(ea>eb)swap(ea,eb);
			if(ea==1 && eb==2){
				cout<<"1111";
			}else if(ea==1 && eb==3 ){
				cout<<"1110";
			}else if(ea==2 && eb==3){
				cout<<"1111";
			}else if(ea==4 && eb==5){
				cout<<"1111";
			}else cout<<"1100";
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c;
	cin>>s;
	cin>>cc;
	cin>>ss;
	if(c!=cc){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
		int z=s[2]-'A'+1;
		int zz=ss[2]-'A'+1;
		if(s[0]+s[1]==ss[0]+ss[1]){
			cout<<1;
			if((z<=3&&zz<=3&&z!=zz)||(z>=4&&zz>=4&&z!=zz)){
				cout<<1;
				if((z+1==zz||z-1==zz)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}
	return 0;
} 

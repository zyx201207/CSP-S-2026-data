#include<bits/stdc++.h>
using namespace std;
signed main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C1;
	cin>>C1;
	int c1=stoi(C1);
	string S1;
	cin>>S1;
	char a=S1.back();
	S1.pop_back();
	int s1=stoi(S1);
	
	string C2;
	cin>>C2;
	int c2=stoi(C2);
	string S2;
	cin>>S2;
	char b=S2.back();
	S2.pop_back();
	int s2=stoi(S2);
	
	//cout<<c1<<" "<<a<<" "<<s1<<"\n";
	//cout<<c2<<" "<<b<<" "<<s2<<"\n";
	
	int ans[4]={};
	if(c1==c2){
		ans[0]=1;
		if(s1==s2){
			ans[1]=1;
			if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
				ans[2]=1;
				if(abs(int(a)-int(b))==1)ans[3]=1;
			}
		}
	}
	
	for(int i=0;i<4;i++)cout<<ans[i];
	return 0;
}

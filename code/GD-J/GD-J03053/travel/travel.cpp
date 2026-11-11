#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int f[10]={1,1,1,2,2,2,0,0,0,0};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1){
		cout<<1;
		if(s2[0]==t2[0]&&s2[1]==t2[1]){
			cout<<1;
			char c1=s2[2]-'A',c2=t2[2]-'A';
			if(f[c1]==f[c2]){
				cout<<1;
				if(c1>c2)  swap(c1,c2);
				if((c1==0&&c2==1)||(c1==1&&c2==2)||(c1==3&&c2==5))cout<<1;
				else  cout<<0;
			}else  cout<<"00";
		}else  cout<<"000";
	}else  cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

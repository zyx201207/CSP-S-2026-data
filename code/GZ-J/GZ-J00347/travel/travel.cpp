//GZ-J00347 赵思成 贵阳市南明区华麟学校 
#include<bits/stdc++.h>
using namespace std;
struct train{
	string c;
	string s;
}a,b;
char f[6]={'0','A','B','C','D','F'};
int flag=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.c>>a.s>>b.c>>b.s;
	if(a.s[2]>b.s[2])swap(a,b);
	if(a.c==b.c){
		cout<<1;
		if(a.s[0]==b.s[0]&&a.s[1]==b.s[1]){
			cout<<1;
			for(int i=1;i<=5;i++){
				if(f[i]=='C')continue;
				if(a.s[2]==f[i]){
					if(b.s[2]==f[i+1]||(b.s[2]==f[i+2]&&i==1)){
						cout<<1;
						flag=1;
						break;
					}
				}
			}if(flag==0){
				cout<<"00";
				return 0;
			}
			for(int i=1;i<=5;i++){
				if(f[i]=='C')continue;
				if(a.s[2]==f[i]){
					if(b.s[2]==f[i+1]){
						cout<<1;
						return 0;
					}
				}
			}cout<<0;
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

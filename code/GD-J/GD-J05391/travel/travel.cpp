#include<bits/stdc++.h>
using namespace std;
int cnt[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=s1[2]-'A';
	int b=s2[2]-'A';
	cnt[a]++;
	cnt[b]++;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(cnt[3]+cnt[4]==2){
				cout<<11;
			}
			else if(cnt[3]+cnt[4]==0){
				cout<<1;
				if(cnt[1]==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

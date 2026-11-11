#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int s_1=(int)(s1[0]-'0')*10+(int)(s1[1]-'0');
	int ss1=(int)(s1[2]-'A')+1;
	int s_2=(int)(s2[0]-'0')*10+(int)(s2[1]-'0');
	int ss2=(int)(s2[2]-'A')+1;
//	cout<<s_1<<" "<<ss1<<" "<<s_2<<" "<<ss2<<endl;
	int k=4;
	if(c1==c2){
		cout<<1;
		k--;
		if(s_1==s_2){
			cout<<1;
			k--;
			if((ss1<=3&&ss2<=3)||(ss1>3&&ss2>3)){
				cout<<1;
				k--;
				if(abs(ss1-ss2)==1) {
					cout<<1;
					k--;
				}
			}
		}
	}
	while(k--) cout<<0;
	return 0;
}


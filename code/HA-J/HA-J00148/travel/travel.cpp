#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
	}
	else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000\n";
		}
		else{
			cout<<"1";
			int a1=s1[2]-'A';
			int a2=s2[2]-'A';
			if((a1==0&&(a2==1||a2==2))||(a1==1&&(a2==0||a2==2))||(a1==2&&(a2==0||a2==1))||(a1==3&&a2==4)||(a1==4&&a2==3)){
				cout<<"1";
				if(abs(a1-a2)==1){
					cout<<"1\n";
				}
				else{
					cout<<"0\n";
				}
			}
			else{
				cout<<"00\n";
			}
		}
	}
	return 0;
}

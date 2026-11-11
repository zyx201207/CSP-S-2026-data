//GZ-J00542 张季萌 同为京学附属实验学校
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("treval.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='C' and s2[2]<='C')||(s1[2]>='D' and s2[2]>='D')){
				cout<<1;
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

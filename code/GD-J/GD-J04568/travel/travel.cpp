#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
map<char,int> mp;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;
	mp['B']=1;
	mp['C']=1;
	mp['D']=2;
	mp['F']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if(mp[s1[2]]==mp[s2[2]]){
				printf("1");
				if(mp[s1[2]]==1){
					if(s1[2]>s2[2])swap(s1,s2);
					if(int(s2[2])-int(s1[2])==1){
						printf("1");
					}else{
						printf("0");
					}
				}else{
					printf("1");
				}
			}else{
				printf("00");
				return 0;
			}
		}else{
			printf("000");
			return 0;
		}
	}else{
		printf("0000");
		return 0;
	}
	return 0;
} 

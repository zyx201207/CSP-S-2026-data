#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	/*
	froepen("travel.in","r",stdin);
	froepen("travel.out","w",stdout);
	你被马扁了 
	*/ 
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]<='D')){
				cout<<"1";
				if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')){
					cout<<"0";
				}else cout<<"1";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}
/*
游记：
这次T123不是很难吧，应该是最简单的了，但我还是不会做（
最后一次考j组了，之后可能是打S或者直接AFO了
学了两三年也没什么长进 颤颤巍巍见自己了属于是 
在csp开茶话会的来 吃了67个薯条（（
luogu 786662 rp++ 
MJ
*/

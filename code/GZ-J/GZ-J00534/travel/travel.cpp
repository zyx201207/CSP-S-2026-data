//GZ-J00534 兴义市弘毅中学 杨凌炜
#include<bits/stdc++.h>
using namespace std;
string n,m,x,y;
bool  s[4]={false};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>x>>y;
	if(n!=x){
		for(int i=0;i<4;i++){
			cout<<s[i];
		}
	}
	else{
		s[0]=true;
		if(m[1]==y[1]&&m[0]==y[0]){
			s[1]=true;
			if((m[2]>='A'&&m[2]<='C')&&(y[2]>='A'&&y[2]<='C')){
			s[2]=true;
			if(m[2]+1==y[2]||m[2]==y[2]+1){
				s[3]=true;
			}
			}
		}
		cout<<s[0]<<s[1]<<s[2]<<s[3];
}
	return 0;
}

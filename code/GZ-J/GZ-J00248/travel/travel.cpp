//GZ-J00248 贵阳市南明区华麟学校 杨瑞泽 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	string a,b;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Node n,m;
	cin>>n.a>>n.b>>m.a>>m.b;
	if(n.a[0]-'0'==m.a[0]-'0'&&n.a[1]-'0'==m.a[1]-'0'){
		if(n.b[0]-'0'==m.b[0]-'0'&&n.b[1]-'0'==m.b[1]-'0'){
			if((n.b[2]<='C'&&m.b[2]<='C')||((n.b[2]<='F'&&n.b[2]>='D')&&(m.b[2]<='F'&&m.b[2]>='D'))){
				if(abs(n.b[2]-'A'-(m.b[2]-'A'))==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

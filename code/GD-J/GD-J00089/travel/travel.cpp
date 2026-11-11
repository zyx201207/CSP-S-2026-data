#include <bits/stdc++.h>
using namespace std;
bool is_true[1001];
int is_guodao[10]={1,1,1,0,114514,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		is_true[1]=1;	
		if(b.substr(0,2)==d.substr(0,2)){
			is_true[2]=1;
			if(is_guodao[b[2]-'A']==is_guodao[d[2]-'A']){
				is_true[3]=1;
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D')){
					is_true[4]=1;
				}
			}
		}
	}

	for(int i=1;i<=4;i++){
		cout<<is_true[i]<<' ';
	}
	return 0; 
}

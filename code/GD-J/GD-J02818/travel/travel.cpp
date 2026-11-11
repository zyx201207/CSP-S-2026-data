#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,c,d,ans="0000";
map<char,int> ma;
int main(){
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
	ma['A']=1;
	ma['B']=1;
	ma['C']=1;
	ma['D']=2;
	ma['F']=2;
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]='1';
			if(ma[d[2]]==ma[b[2]]){
				ans[2]='1';	
				if(b[2]+1==d[2]||d[2]+1==b[2]){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

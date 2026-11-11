//刘子逍 北京师范大学贵阳附属中学 GZ-J00306 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
string c1,s1,c2,s2;
map<char,int> m;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	m['A']=1,m['B']=1,m['C']=1,m['D']=2,m['F']=2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(m[s1[2]]!=m[s2[2]]) cout<<"00";
	else if(m[s1[2]]==m[s2[2]]){
		cout<<1;
		if(m[s1[2]]==2 || abs(s1[2]-s2[2])==1) cout<<1;
		else cout<<0;
	}
	cout<<'\n';
	fclose(stdin);fclose(stdout);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;

bool is3(string a, string b){
	if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
		if(b[2]=='A'||b[2]=='B'||b[2]=='C')return true;
		else return false;
	}else{
		if(b[2]=='D'||b[2]=='E')return true;
		else return false;
	}
}
bool is4(string a, string b){
	char aa=a[2], bb=b[2];
	if(aa>bb)swap(aa, bb);
	if(aa+1==bb)return true;
	else return false;
}


int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string c1, s1, c2, s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	
	string res="0000";
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		res[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			res[1]='1';
			if(is3(s1, s2)==true){
				res[2]='1';
				if(is4(s1, s2)==true){
					res[3]='1';
				}
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}

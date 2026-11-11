#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c_1,c_2;
string s_1,s_2;
bool x,y,z,w;
bool f(char a,char b){
	if(a == 'A' || a == 'B' || a == 'C'){
		return (b == 'A' || b == 'B' || b == 'C');
	}
	if(a == 'D' || a == 'F'){
		return (b == 'D' || b == 'F');
	}
	return false;
}
bool g(char a,char b){
	if(a > b){
		swap(a,b);
	}
	if(a=='A' && b == 'B'){
		return true;
	}
	if(a == 'B' && b == 'C'){
		return true;
	}
	if(a == 'D' && b == 'F'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("D:\\cspj\\down\\travel\\travel1.in","r",stdin);
//	freopen("D:\\cspj\\down\\travel\\out.txt","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	x = (c_1 == c_2);
	y = x && (s_1.substr(0,2) == s_2.substr(0,2));
	z = y && f(s_1[2],s_2[2]);
	w = z && g(s_1[2],s_2[2]);
	cout<<x<<y<<z<<w<<endl;
	return 0;
} 

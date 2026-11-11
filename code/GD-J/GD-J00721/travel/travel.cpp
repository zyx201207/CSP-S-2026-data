#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b){
	int len=a.size(),len1=b.size();
	if(len!=len1)return false;
	for(int i=0;i<a.size();i++){
		if(a[i]>'9'||a[i]<'0')return true;
		if(a[i]!=b[i])return false;
	}	
	return true;
}
bool check1(char g,char h){
	if(g>h){
		char tmp=g;
		g=h;
		h=tmp;
	}
	if(g<='C'){
		if(h>='D')return false;
		else return true;
	}else return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e,f;
	cin>>a>>b>>c>>d;
	for(int i=0;i+1<b.size();i++)e+=b[i];
	for(int i=0;i+1<d.size();i++)f+=d[i];
	char ch=b[(int)b.size()-1],ch1=d[(int)d.size()-1];
	if(a==c){
		cout<<1;
		if(check(b,d)){
			cout<<1;
			if(e==f&&check1(ch,ch1)){
				cout<<1;
				if(ch+1==ch1&&ch!='C'||ch1+1==ch&&ch1!='C')cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 

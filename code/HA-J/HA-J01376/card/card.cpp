#include<bits/stdc++.h>
using namespace std;
int n,m,y,p=1;
char c[200005];
int a[300005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;/*
	s="000";
	s=s.substr(0,1);
	cout<<s;*/
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	//s+=c[1];
	//a[(int)c[1]-'0']+=1;
	while(p<=n){
		for(int i=p;i<=n;i++){
			int x=s.find(c[i]);
			if(x<s.size()&&x>=0){
				s=s.substr(0,x)+c[i];
			}else s+=c[i];
//			cout<<s<<endl;
		}
		for(int j=1;j<=m;j++){
			y=s.find((char)j+'0');
//			cout<<y<<" ";
			if(y<s.size()&&y>=0) a[j]++;
		}
//		cout<<endl;
		p++;/*
		int d,b;
		if(p-1<(s.size()-1)) d=p-1;
		else d=s.size()-1;
		if(0<(s.size()-p+1)) b=s.size()-p+1;
		else b=0;
		s=s.substr(d,b);*/
		s="";
	}
	
	//cout<<s.find('2');
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

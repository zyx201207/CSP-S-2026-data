#include<bits/stdc++.h>
using namespace std;
#define name first
#define Long second
string plt(string i,int j){
	return i+" "+to_string(j);
}int main(){
	map<string,int>m;
	int linenum,stanum,gonum,p,q;
	cin>>p>>linenum>>stanum>>q>>gonum;
	p=0;
	vector<pair<string,int>>v[stanum+linenum+3];
	int exit_sta[stanum]={};
	for(int i=0;i<stanum;i++)cin>>exit_sta[i];
	for(int i=0;i<linenum;i++){
		m["line "+to_string(i+1)]=p++;
		cout<<"m[line "+to_string(i+1)<<"]="<<m[plt("station",i+1)]<<" i="<<i<<endl;
	}for(int i=0;i<stanum;i++)m["station "+to_string(i+1)]=p++;
	for(int i=1,num;i<=linenum;i++){
		cin>>num;
		pair<string,int>ss;
		ss.name="line "+to_string(i);
		for(int j=0,sta,lon;j<num;j++){
			cin>>sta>>lon;
			pair<string,int>s;
			s.name="station "+to_string(sta);
			s.Long=lon;
			ss.Long=lon;
			v[m[plt("line",i)]].push_back(s);
			cout<<"m[line"+to_string(i)+"]="<<m["line "+to_string(i)]<<endl;
			cout<<"v[m[line"+to_string(i)+"]].push_back(<"<<s.name<<' '<<s.Long<<">)\n";
			v[m[plt("station",sta)]].push_back(ss);
		}
	}for(int i=1;i<=linenum;i++){
		string sss="line "+to_string(i);
		cout<<sss<<' '<<"station:\n";
		for(int j=0;j<v[m[sss]].size();j++)cout<<"	v[m["<<sss<<"]]["<<j<<"]:"<<v[m[sss]][j].name<<' '<<v[m[sss]][j].Long<<endl;
		cout<<endl;
	}for(int i=1;i<=stanum;i++){
		string sss=plt("station",i);
		cout<<sss<<' '<<"line:\n";
		for(int j=0;j<v[m[sss]].size();j++)cout<<"	v[m["<<sss<<"]]["<<j<<"]:"<<v[m[sss]][j].name<<' '<<v[m[sss]][j].Long<<endl;
		cout<<endl;
	}int floyd[stanum+linenum+1][stanum+linenum+1];
}

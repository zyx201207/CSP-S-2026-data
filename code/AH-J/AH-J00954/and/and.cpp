#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const string adsg="and";
bool cmp(int a,int b){return a>b;}
int pdasfg(vector<int> a,int b){
	int d=2147483647;
	for(int i=0;i<=31;i++){
		for(int j=1;j<a.size();j++){
			if(i==b)continue;
			if(!((1<<i)&a[j])){d-=(1<<i);break;}
		}
	}return d;
}
int main(){
//	freopen((adsg+".in").c_str(),"r",stdin);
//	freopen((adsg+".out").c_str(),"w",stdout);
/*	int n,m;cin>>n>>m;
	vector<int> ns(n+1);
	bool a=1;
	for(int i=1;i<=n;i++){bool d=0;
		cin>>ns[i];for(int j=1;j<=32&&a;j++){if(1<<j==ns[i]+1){d=1;break;}}
		if(!d)a=0;
	}if(m==1){sort(ns.begin()+1,ns.end(),cmp);cout<<ns[1];return 0;}
	if(m==n){int a=ns[1];for(int i=2;i<=n;i++){a&=ns[i];}cout<<a;return 0;}
	if(m==n-1){
		
	}
	if(a){sort(ns.begin()+1,ns.end(),cmp);cout<<ns[m];}*/
	int n;cin>>n;
	vector<int> a(n+1);for(int i=1;i<=n;i++)cin>>a[n];
	for(int i=1;i<=n;i++){
		cout<<pdasfg(a,i);
	}
}

#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct Node{
	int time_t,
};
int a[500001],sum[501],on_foot[500001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int n,m,d,q,k=0;
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>on_foot[i];
	}
	string s;
	getline(cin,s);
	for(int i=1;i<=n;i++){
		int p=k,o=0,f=0;
		getline(cin,s);
		cout<<s<<"\n";
		for(;o<s.size();o++)
			if(s[o]==' ') a[++k]=f,f=0;
			else f*=10,f+=(s[o]-'0');
		a[++k]=f,f=0;
		sum[i]=sum[i-1]+k-p;
	}
	if(k/n==2){
		for(int i=1;i<=r;i++){
			int sta,end;
			cin>>sta>>end;
			while(!q.empty()){
				
			}
		}
	}
	else{
		for(int i=1;i<=r;i++){
			int sta,end;
			cin>>sta>>end;
		
		}
	}
	return 0;
}
/*
This is the smallest tree£¬but I don't know (T_T)(T_T) 
But I can find some keywords and have some ...(you know that I want to )
First , on foot time
second , scan
third , if k/n is 2 , I can use that to have some nice keywords
last , I must find all. But the time will TLE!
*/

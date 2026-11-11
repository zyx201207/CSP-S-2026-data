#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b;
	long long n,m,x,y;
	cin>>n>>x>>a>>m>>y>>b;
	if(n==m) cout<<"1";
	else cout<<"0";
	if(n==m and x==y) cout<<"1";
	else cout<<"0";
	bool flag=true;
	if(n==m){
		if(x==y){
			if(a=='A' and b=='B') cout<<"1";
			else if(a=='A' and b=='C') cout<<"1";
			else if(a=='B' and b=='C') cout<<"1";
			else if(a=='D' and b=='F') cout<<"1";
			else if(b=='A' and a=='B') cout<<"1";
			else if(b=='A' and a=='C') cout<<"1";
			else if(b=='B' and a=='C') cout<<"1";
			else if(b=='D' and a=='F') cout<<"1";
			else{
				cout<<"0";
				flag=false;	
			}
		}else{
			cout<<"0";
			flag=false;	
		}
		
	}else{
		cout<<"0";	
		flag=false;
	}
	if(flag==true){
		long long sux=(long long)a,suy=(long long)b;
		long long minn=min(sux,suy),maxn=max(sux,suy);
		if(minn+1==maxn) cout<<"1";
		else if(a=='D' and b=='F') cout<<"1";
		else if(a=='F' and b=='D') cout<<"1";
		else cout<<"0";
	}else cout<<"0";
	return 0;
} 

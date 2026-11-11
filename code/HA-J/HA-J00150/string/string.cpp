#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s;
long long n,os;
long long ans2;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	set<string> S;
	while(n--){
		int m;
		string a;
		cin>>m>>a;
		S.insert(a);
		for(int i=1;i<=m;i++)s+=a;
	}	
	if(S.size()==1){
		cout<<0;
		return 0;
	}
	string b,d;
	int cnt=s.size();
	
	if(cnt%2==0){
		for(int i=0;i<cnt/2;i++){
			b[i]=s[i];
		}string c=b;
		for(int i=cnt/2-1;i>=0;i--){
			c[ans++]=b[i];
		}
		for(int i=cnt/2;i<=cnt;i++){
			d[ans2++]=s[i];
		}
		for(int i=0;i<=max(ans,ans2);i++){
			if(c[i]!=d[i])os++;
		}
	}else{cout<<cnt/2;
	    return 0;
	}
     cout<<os;
	
	return 0;
}
//3
//2 a
//2 b
//2 c



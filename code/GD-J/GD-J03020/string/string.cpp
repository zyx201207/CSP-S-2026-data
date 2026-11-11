#include <bits/stdc++.h>
using namespace std;
long long t=1;
void G(int a,int b){
	if(b==0) {
		t=a;
		return ;
	}
	G(b,a%b);
}
string s;
const int N=2e5+10;
int g[N];
	char c[N];
int main(){
		freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
int n;
cin>>n;
long long cnt=0;
for(int i=0;i<n;i++){
	
	cin>>g[i];

	cin>>c[i];
	cnt+=g[i];
	
	
}

t=g[0];
for(int i=1;i<n;i++){
	G(g[i],t);
}

for(int i=0;i<n;i++){
	
	for(int j=0;j<(g[i]/t);j++){
		s+=c[i];
	}
	
	
}


int ans=0;
 
cnt/=t;

if(cnt%2!=0){
	int a=cnt/2;

	for(int i=1;(a-i)>=0;i++){
		if(s[a-i]!=s[a+i]){
		
		ans++; 
		
	}
	}
}else {
	int a=cnt/2;
	int b=a-1;

	for(int i=0;i<=b;i++){
		if(s[a+i]!=s[b-i]){
		ans++;
		}
	}
}

cout<<(ans*t);
	
	
	return 0; 
}

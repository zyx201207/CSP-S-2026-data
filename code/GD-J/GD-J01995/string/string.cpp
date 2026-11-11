#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
queue<char> q;
int cnt;
string s;
int flag=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
	}
	
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i+1]){
			flag==0;
			break;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}else if(flag==0){
		//while(!check(s)){
			
		//}
	}
	return 0;
} 

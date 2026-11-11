#include<bits/stdc++.h>
using namespace std;
char a[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int s;
	char d;
	int u;
	long long dfg=1;
	long long v=0;
	long long cou=0;
	cin>>u;
	for(int i=1;i<=u;i++){
		cin>>s>>d;
		v+=s;
		for(int y=dfg;y<=v;y++){
			a[y]=d;
		}
		dfg=v+1;
		
	}
	long long h=v/2;
	for(int k=1;k<=h;k++){
		if(a[k]!=a[v-k+1])cou++;
	}
	cout<<cou;
	
	return 0;
}

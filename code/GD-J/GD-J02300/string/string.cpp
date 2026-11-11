#include<bits/stdc++.h>
using namespace std;

int m[20000005];
string s[2000005];
string ant;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>s[i];
		for(int j=1;j<=m[i];j++){
			ant+=s[i];
		}
	}
	int c=ant.size();
	for(int i=0;i<=ant.size();i++){
		cout<<ant[i];
		if(ant[i]==ant[c+1-i]){
			num=0;
		}else num++;
	}
	cout<<num;
	return 0;
}

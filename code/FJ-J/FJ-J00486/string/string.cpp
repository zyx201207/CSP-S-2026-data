#include<bits/stdc++.h> 
using namespace std;

int n;//Cici
long long sum=0;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);//Little Emperor
	for(int i=0;i<n;i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		for(int j=0;j<a;j++) {
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long int maxn=1e15+5;
char sss[maxn],ss[maxn];
int main() {
	string s; 
	long long int n,m,count=0,k=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>s;
		for(int z=k;z<m;z++){
			ss[z]=sss[i];	
		}k+=m;
	}for(int i=0;i<m;i++){
		if(ss[i]!=ss[m-i-1]){
			count++;
		}
	}cout<<count;
	return 0;
}/*6
100000000 a
100000000 a
100000000 a
100000000 b
100000000 b
100000000 b*/

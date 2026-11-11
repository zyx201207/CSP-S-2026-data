//GZ-J00716 北京师范大学贵阳附属中学 邹骐骏;
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b){
	if(a<=b){
		return a;
	}
	return b;
}
int f(string n,string m){
	long long a=2;
	for(int i=min(n.size(),m.size());i>=0;i--){
		if(n[i]=="1" and n[i]==m[i]){
			for(int j=1;j<i;j++){
				a*=2;
			}	
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	string a[n+1];
	int ans[n+1];
	for(int i=0;i<n;i++){
		long long o;
		int l=0;
		string b="";
		cin >>o;
		while(o>=1){
			l++;
			if(o%2==0){
				b+="0";
				o=o/2;
				continue;
			}
			o=o/2;
			b+="1";
		}
		for(int j=l-1;j>=0;j--){
			a[i]+=b[j];
		}
	}
	for(int i=0;i<n;i++){
		
	}
}

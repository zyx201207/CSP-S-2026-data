//GZ-J00698 º½ÌìÖÐÑ§ ¸¶²©ìÚ 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int a,z;
	cin>>a>>z;
	long long int s[a];
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	long long int p[a];
	long long int maxx=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(s[j]>maxx){
				maxx=s[j];
				s[j]=0;
			}
		}
		p[i]=maxx;
		maxx=0;
	}
	cout<<p[z-1];
	
}


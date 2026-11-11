#include<bits/stdc++.h>
using namespace std;
int n;
long long s[200005];
char z[200005];
string k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long r=0,l=1;
	for(long long i=1;i<=n;i++){
			cin>>s[i];
			cin>>z[i];
			r+=s[i];
	}
	long long an=0;
	long long l1=1,r1=n,zl=0,zr=0;
	for(;l<=r&&l1<=r1;){
		
			long long o=min(s[l1]-zl,s[r1]-zr);
			l+=o;
			r-=o;
			if(s[r1]-zr>s[l1]-zl){
				l1++;
				zl=0;
				zr+=o;
			}
			else if(s[r1]-zr<s[l1]-zl){
					r1--;
					zr=0;
					zl+=o;
			}
			else{
					l1++,r1--;
					zl=0;zr=0;
					
			}
			if(z[l1]!=z[r1]){
				an+=o;
				
			}
			
	}
cout<<an;
	return 0;
}

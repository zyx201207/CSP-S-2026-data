#include<bits/stdc++.h>
using namespace std;

struct ac{
	long long a;
	string c;
};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long k=0;
	cin>>n;
	ac s[n+5];
	long long l=0;
	long long x=0,y=n-1;
	long long q;
	if(n%2==0){
		q=n/2;
	}
	else{
		q=n/2+1;
	}
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
		l+=s[i].a;
	}
	
	while(x<=y){
		if(n%2==0){
			if(s[x].a==s[y].a){	
				if(s[x].c!=s[y].c){
					k+=s[x].a;
				}
			}
			else{
				if(s[x].c!=s[y].c){
					k+=max(s[x].a,s[y].a);
				}
			}
			x++;
			y--;
		}
		else{
			if(s[x].a==s[y].a){	
				if(x==y&&l%2!=0){
					k++;
				}
				else if(s[x].c!=s[y].c){
					k+=s[x].a;
				}
			}
			else{
				if(s[x].c!=s[y].c){
					k+=max(s[x].a,s[y].a);
				}
			}
			x++;
			y--;
		}
	}
	cout<<k;
	
	return 0;
}

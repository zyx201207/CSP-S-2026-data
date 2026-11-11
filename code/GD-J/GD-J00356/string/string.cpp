#include<bits/stdc++.h>
using namespace std;

long long cnt,cns,n;
struct anc{
	long long a;
	string b;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	long long i=1,j=n,k=0,l;
	l=s[n].a;k=s[1].a;
	while(i<j){
		if(i==j) break;
		
		while(1){
			if(s[i].b!=s[j].b){
				if(k>=l){
					k-=l;
					j--;
					cnt+=l;l=s[j].a;
					break;
				}
				else{
					l-=k;
					i++;
					cnt+=k;k=s[i].a;
					break;
				}
			}
			else{
				if(k>=l){
					k-=l;
					j--;l=s[j].a;
					break;
				}
				else{
					l-=k;
					i++;k=s[i].a;
					break;
				}
			}	
		}
	}
	cout<<cnt;
	return 0;
} 

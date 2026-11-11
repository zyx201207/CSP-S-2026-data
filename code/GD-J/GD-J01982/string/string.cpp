#include<bits/stdc++.h>
using namespace std;
struct nd{
	long long n;
	char a;
}s[201000];
int k;
long long m=0,nl=0,nr=0;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int u;
	cin>>u;
	if(u==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=u;i++){
		scanf("%lld%s",&s[i].n,&s[i].a);
		m+=s[i].n;
	}
	long long p=m/2;
	
		int l=1,r=u;
		while(l<r){
			if(s[l].n<s[r].n){
				if(s[l].a==s[r].a){
					s[r].n-=s[l].n;
					l++;
				}else{
					nl+=s[l].n;
					s[r].n-=s[l].n;
					l++;
				}
			}else{
				if(s[l].a==s[r].a){
					s[l].n-=s[r].n;
					r--;
				}else{
					nl+=s[r].n;
					s[l].n-=s[r].n;
					r--;
				}
			}
		}
	cout<<nl;
	return 0;
}

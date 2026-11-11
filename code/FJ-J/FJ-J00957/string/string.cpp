#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,c=0;
	cin>>a;
	long long n[a];
	char m[a];
	for(long long i=0;i<a;i++){
		cin>>n[i]>>m[i];
		c+=n[i];
	}
	if(c%2==1)c=c/2+1;
	else c=c/2;
	long long k=a-1,w=0,l=0,p=0;
	while(p<c){
		long long minn=min(n[k],n[w]);
		if(m[w]!=m[k])l+=minn;
		if(n[k]>n[w]){
			n[k]-=n[w];
			w++;
			p+=n[w];		
		}else if(n[k]<n[w]){
			n[w]-=n[k];
			k--;
			p+=n[k];		
		}else{
			w++;
			k--;
			p+=n[w];
		}
	}
	cout<<l;
	return 0;
}

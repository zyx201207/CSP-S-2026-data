//GZ-J00524 兴义市弘毅中学 卢浩宇 
#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,sum=0;
char a;
string b,c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
   cin>>n;
   for(long long i=1;i<=n;i++){
		cin>>m;
		getchar();
		cin>>a;
		for(long long j=1;j<=m;j++){
			s[++sum]=a;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
    if(n%2!=0){
		int l=1,r=sum;
		int mid=(l+r)/2;
		for(int i=1;i<mid;i++){
			b[i]=s[i];
		}
		for(int i=1;i<mid;i++){
			c[i]=s[++mid];
			if(b[--mid]!=c[i]) cnt++;
		}
	}
     else{
		int l=1,r=sum;
		int mid=(l+r)/2;
		int last=mid+1;
		for(int i=1;i<=mid;i++){
			b[i]=s[i];
		} 
		for(int i=1;i<=mid;i++){
			c[i]=s[++mid];
			if(b[--last]!=c[i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 

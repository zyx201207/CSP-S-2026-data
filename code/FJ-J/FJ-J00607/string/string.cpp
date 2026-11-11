#include<bits/stdc++.h>
using namespace std;
int n,x,y;
long long m,k=1,ans;
struct Node{
	long long len;
	char c;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].len>>s[i].c;
		m+=s[i].len;
	}
	x=1,y=n;
	while(k<(m+1)/2){
		if(x==y){
			break;
		}
		long long a=s[x].len,b=s[y].len;
		if(s[x].c!=s[y].c){
			if(a>b){
				s[x].len-=b,y--;
				ans+=b,k+=b;
			}else if(a<b){
				s[y].len-=a,x++;
				ans+=a,k+=a;
			}else{
				x++,y--;
				ans+=a,k+=a;
			}
		}else{
			if(a>b){
				s[x].len-=b,y--,k+=b;
			}else if(a<b){
				s[y].len-=a,x++,k+=a;
			}else{
				x++,y--,k+=a;
			}
		}
	}
	cout<<ans;
	return 0;
}

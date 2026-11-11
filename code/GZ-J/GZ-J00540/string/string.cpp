//GZ-J00540 顾浩扬 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string s;
long long n,p,y,m;
char a;
long long x;
void apt(long long e){
	for(int i=1;i<=e;i++)
		s+=a;	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    scanf("%lld",&n);
    
	for(long long i=1;i<=n;i++){
    	scanf("%lld %c",&x,&a);
		apt(x);	
	}
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
    	if(s[i]!=s[j]) y++;
	}
	printf("%lld",y);
	return 0;
} 

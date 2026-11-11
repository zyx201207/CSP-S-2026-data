#include<bits/stdc++.h>
using namespace std;
long long k,n,x,m;
char y;
struct ss{
	char x;
	long long y;
}s[2000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d%s",&x,&y); 
    	if(s[m].x==y){
    		s[m].y+=x;
		}else{
			s[++m].x=y;
			s[m].y=x;	
		}
	}
	for(int i=1;i<=m/2;i++){
		if(s[i].x!=s[m-i+1].x){
			k+=(s[i].y+s[m-i+1].y)/2;
			if(((s[i].y+s[m-i+1].y)%2)!=0){
				k++;
			}
		}else if(s[i].y!=s[m-i+1].y){
			k+=abs(s[i].y-s[m-i+1].y)/2;
			if((abs(s[i].y-s[m-i+1].y))%2!=0){
				k++;
			}
		}
	}
	printf("%lld",k);
	return 0;
}



#include<bits/stdc++.h>
using namespace std;

struct Node{
	int num;
	char c;
}sss[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&sss[i].num,&sss[i].c);
	}
	int l=1,r=n;
	while(l<r){
		if(sss[l].c==sss[r].c){
			if(sss[l].num<sss[r].num){
				sss[r].num-=sss[l].num;
				l++;
			}
			else if(sss[l].num>sss[r].num){
				sss[l].num-=sss[r].num;
				r--;
			}
			else{
				l++;r--;
			}
		}else{
			if(sss[l].num<sss[r].num){
				ans+=sss[l].num;
				sss[r].num-=sss[l].num;
				l++;
			}
			else if(sss[l].num>sss[r].num){
				ans+=sss[r].num;
				sss[l].num-=sss[r].num;
				r--;
			}
			else{
				ans+=sss[r].num;
				l++;r--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 

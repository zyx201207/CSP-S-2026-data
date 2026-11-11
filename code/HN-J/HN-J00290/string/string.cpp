#include<bits/stdc++.h>
using namespace std;
struct str{
	int geshu;
	char zimu;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,sum=0,cnt_number=0;
	char S[1000000000]={};
	str huiwen[200000]={};
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%n",&huiwen[i].geshu,&huiwen[i].zimu);
		for(int j=0;j<huiwen[i].geshu;i++){
			S[cnt+j]=huiwen[i].zimu;
		}
		cnt+=huiwen[i].geshu;
	}
	if(cnt%2!=0){
		sum=cnt/2+1;
		for(int i=1;i <= cnt/2;i++){
			if(S[sum+i]==S[sum-i]){
				continue;
			}else{
				cnt_number++;
			}
		}
	}else{
		sum=cnt/2;
		for(int i=1;i<=sum;i++){
			if(S[sum+i]==S[sum+i-1]){
				continue;
			}else{
				cnt_number++;
			}
		}
	}
	printf("%d",&cnt_number);
	return 0;
}

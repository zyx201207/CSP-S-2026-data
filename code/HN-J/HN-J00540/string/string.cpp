#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct letters{
	ll cnt;
	char letter;
};

int n,cnt_let;
ll len,res;
letters lst[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	char last='0',now;
	ll temp,sum_cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&temp,&now);
		len+=temp;
		if(i!=1&&last!=now){
			lst[++cnt_let]={sum_cnt,last};
			sum_cnt=temp;
		}
		else{
			sum_cnt+=temp;
		}
		last=now;
	}
	lst[++cnt_let]={sum_cnt,last};
	int i1=1,i2=cnt_let;
	while(1){
		if(lst[i1].cnt>lst[i2].cnt){
			lst[i1].cnt-=lst[i2].cnt;
			if(lst[i1].letter!=lst[i2].letter){
				res+=lst[i2].cnt;
			}
			i2--;
		}
		if(lst[i1].cnt==lst[i2].cnt){
			if(lst[i1].letter!=lst[i2].letter){
				res+=lst[i2].cnt;
			}
			i1++;
			i2--;
		}
		if(lst[i1].cnt<lst[i2].cnt){
			lst[i2].cnt-=lst[i1].cnt;
			if(lst[i1].letter!=lst[i2].letter){
				res+=lst[i1].cnt;
			}
			i1++;
		}
		if(i1>=i2){
			break;
		}
	}
	printf("%lld",res);
	return 0;
}


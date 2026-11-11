#include <bits/stdc++.h>
using namespace std;
struct aaa{
	long long geshu;
	char zimu;
};
long long n,num,ge;
char pwq;
aaa cun[299999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>num;
		cin>>pwq;
		cun[i].geshu=num;
		cun[i].zimu=pwq;
	}
	int j=1;
	while(1){
		if(j==n){
			cout<<ge;
			return 0;
		}
		if(cun[j].zimu==cun[n].zimu){
			if(cun[j].geshu>cun[n].geshu){
				cun[j].geshu-=cun[n].geshu;
				n--;
			}
			else{
				cun[n].geshu-=cun[j].geshu;
				j++;
			}
		}
		else{
			if(cun[j].geshu>cun[n].geshu){
				ge=ge+cun[n].geshu;
				cun[j].geshu-=cun[n].geshu;
				n--;
			}
			else{
				ge=ge+cun[j].geshu;
				cun[n].geshu-=cun[j].geshu;
				j++;
			}
		}
	}
	cout<<ge;
	return 0;
}

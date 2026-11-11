#include<bits/stdc++.h>
using namespace std;
int card1[500005],card2[500005],kind1[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int num,kind,left=1;
	cin>>num>>kind;
	for(int i=1;i<=num;i++){
		cin>>card1[i];
	}
	for(int i=1;i<=kind;i++){
		for(int j=left;j<=num;j++){
			card2[j]=card1[j];
		}
	}
	return 0;
}

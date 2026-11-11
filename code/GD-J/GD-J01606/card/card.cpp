#include<bits/stdc++.h>
using namespace std;
int num[300005];
bool numm[300005];
int card[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int a=1;a<=n;a++){
		cin>>card[a];
	}
	for(int a=1;a<=n;a++){
		for(int b=a;b<=n;b++){
			if(numm[card[b]]==false){
				numm[card[b]]=true;
			}
			else if(numm[card[b]]==true&&card[b]!=0){
				for(int j=a;j<b;j++){
					if(card[j]==card[b]){
						for(;j<b;j++){
							numm[card[j]]=false;
							card[j]=0;
						}
						break;
					}
				}
			}
		}
		for(int k=1;k<=n;k++){
			num[card[k]]++;
		}
	}
	for(int a=1;a<=m;a++){
		cout<<num[a]<<" ";
	}
	return 0;
}

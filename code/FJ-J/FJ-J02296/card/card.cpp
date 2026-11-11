#include<bits/stdc++.h>
using namespace std;
int c[20005],e[20005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long a,b,d;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int t=1;t<=a;t++){
		for(int i=t;i<=a;i++){
			d=c[i];
			e[d]++;
			for(int j=a;j>i;j--){
				if(c[j]==d){
					i=j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=b;i++){
		cout<<e[i]<<" ";
	}
	return 0;
}

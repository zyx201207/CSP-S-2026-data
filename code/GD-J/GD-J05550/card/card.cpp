#include<bits/stdc++.h>
long long card[500005],now[500005],num[300005],e[300005]; 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	long long a,b;
	for(int i=1;i<=n;i++){
		a=1;
		for(int j=i;j<=n;j++){
			if(num[card[j]]){
				b=num[card[j]]; 
				for(int k=num[card[j]];k<a;k++)num[now[k]]=0;
				a=b;
			}
			now[a]=card[j];
			num[card[j]]=a;
			a++;

		}
		for(int j=1;j<a;j++){
			e[now[j]]++;
		}
		for(int j=1;j<=m;j++)num[j]=0;
	}
	
	for(int i=1;i<=m;i++)cout<<e[i]<<" ";
	
	
	return 0;
}

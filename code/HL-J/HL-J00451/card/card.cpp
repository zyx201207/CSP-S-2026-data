#include <bits/stdc++.h>
using namespace std;
int num[300005], a[300005], card_ku[500005], sum;
int find(int x){
	for (int i=1;i<=sum;i++){
		if (a[i]==x){
			return i;
		}
	}
	return 0;
}
void playing (int i,int n, int m){
	for (int j=i;j<=n;i++){
		int x=find(card_ku[j]);
		if (x==0){
			a[j-i+1]=card_ku[j];
			sum++;
		}
		else{
			for (int l=x+1;l<=sum;i++){
				a[l]=0;
			}
			sum=x;
		}
	}
	for (int j=1;j<=n-i+1;j++){
		num[a[j]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>card_ku[i];
	}
	for (int i=1;i<=n;i++){
		playing(i, n, m);
		memset(a,0,sizeof(a));
	}
	for (int i=1;i<=m;i++){
		cout<<num[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
long long cnt[300005];
int a[300005];
long long b[300005];
long long num;
void up(long long n){
	while(n>0){
		cnt[n%10]++;
		n/=10;
	}
}
void up1(){
	for(int i=1;i<=300005;i++){
		a[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		num=0;
		up1();
		for(int j=i;j<=n;j++){

			a[b[j]]++;
			if(a[b[j]]==2){
				up1();
				num=0;
			}
			num=num*10+b[j];
		}

		up(num);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9+7,maxm=2e5+5;
char a[maxn],d[maxm];
int b[maxm];
long long n,num=0,cnt=0;
int sum(int x,int y){
	if(y==0)return x;
	return sum(y,x%y);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>d[i];
	}
	long long c=sum(b[1],b[2]);
	for(int i=2;i<n;i++){
		c=sum(c,b[i+1]);
	}
	for(int i=1;i<=n;i++){
		b[i]/=c;
	}
	for(int i=1;i<=n;i++){
		while(b[i]--){
			a[++num]=d[i];
		}
	}
	int j=num;
	for(int i=1;i<=(num-1)/2+1;i++){
		if(a[i]!=a[j]){
			cnt++;
		}
		j--;
	}
	cout<<cnt*c;
	fclose(stdin);
	fclose(stdout);
  return 0;
}

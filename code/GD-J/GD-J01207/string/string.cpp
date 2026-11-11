#include<iostream>
#include<cstdio>
using namespace std;
long long n,cnt,l,mid,k,s,e;
struct node{
	long long num;
	char c;
}a[200005];
char cs[10000005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		a[i].num+=a[i-1].num;
		for(int j=a[i-1].num+1;j<=a[i].num;j++) cs[j]=a[i].c;
	}
	l=a[n].num,s=1,e=l;
	while(s<e){
		if(cs[s]!=cs[e]) cnt++;
		s++,e--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

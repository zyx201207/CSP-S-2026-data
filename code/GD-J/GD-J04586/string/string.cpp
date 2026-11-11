#include <bits/stdc++.h>
using namespace std;
const int N=200010;
long long n;
struct node{
	int a;
	char ch;
}p[N];
node ans[N];
long long num=0;
char str[N*500+10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long temp=1;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		cin>>p[i].a>>p[i].ch;
		long long j=temp;
		sum+=p[i].a;
		for(;j<temp+p[i].a;j++) str[j]=p[i].ch;
		temp=j;
	}
	for(long long i=1,j=sum;i<=j;i++,j--){
		if(str[i]!=str[j]) num++;
	}
	cout<<num<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}


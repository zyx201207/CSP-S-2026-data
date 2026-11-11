#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long n,a,k=1,cnt=0,l=0;
char s;
int st[10000005],bh[10000005];
void back_half(){
	for(int i=1;i<=(ceil)((float)l/2.0);i++){
		bh[i]=st[l-i+1];
	}
	return ;
}
long long pd(){
	int x=0;
	for(int i=1;i<=(ceil)((float)l/2.0);i++){
		if(st[i]!=bh[i])x++;
	}
	return x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		l+=a;
		for(int j=1;j<=a;j++){
			st[k]=s;
			k++;
		}
	}
	back_half();
	cout<<pd();
	return 0;
}

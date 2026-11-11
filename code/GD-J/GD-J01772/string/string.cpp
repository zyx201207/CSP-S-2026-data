#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],&c[i]);
	}
	long long cnt=0;
	int i=1,j=n;
	for(;;){
		if(i==j)break;
		if(i>j)break;
//		cout<<"i="<<i<<" j="<<j<<endl;
		if(c[i]==c[j]){
//			cnt+=abs(a[i]-a[j]);
		}else{
			cnt+=min(a[i],a[j]);
		}
		int _=min(a[i],a[j]);
		a[i]-=_;
		a[j]-=_;
//		cout<<a[i]<<" "<<a[j]<<" cnt="<<cnt<<endl;
		if(!a[i])i++;
		if(!a[j])j--;
	}
	printf("%lld",cnt);
	return 0;
}
/*
6
3 a
5 g
7 e
2 e
2 b
4 a

5
aaagggggeeeeeeeeebbaaaa
*/

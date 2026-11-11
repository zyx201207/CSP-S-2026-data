#include <bits/stdc++.h>
using namespace std;
int n,len=0,num=0;
char ans[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int len_i;
		char c;
		cin>>len_i>>c;
		for(int j=1;j<=len_i;j++)
			ans[++len]=c;
	}
	int l=1;
	int r=len;
	while(l<=r){
		if(ans[l]!=ans[r]) num++;
		l++;
		r--;
	}
	printf("%d",num);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,num,cnt,cnt2,cnt3,cnt4;
char s;
string a,b,c;//表示拆分后的前后两个数组 
string ss;//拼接的数组 
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>num>>s;
		for(int i=1;i<=num;i++){
			ss[++cnt]=s;
		}
	}
	int l=1,r=cnt;
	int mid=(l+r)/2;
	for(int i=0;i<=mid;i++){
		a[cnt2++]=ss[i];
	}
	for(int i=mid;i<=cnt;i++){
		b[cnt3++]=ss[i];
	}
	for(int i=cnt3;i>=0;i--){
		c[cnt4++]=b[i];
	}
	for(int i=1;i<=mid;i++){
		if(a[i]!=c[i])ans++;
	}
	cout<<ans;
	return 0;
}

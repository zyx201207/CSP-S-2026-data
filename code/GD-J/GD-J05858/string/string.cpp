#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
long long len;
long long ans;
int c[200010];
char ch;
int main(){
	//双指针欸嘿嘿
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch;
		c[i]=ch-'a';
		len+=a[i];
	}
	long long l=1,r=len,le=1,ri=n,le1=a[1],ri1=a[n];//双指针 
	while(l<r&&le<ri){//判边界 
		//cout<<l<<' '<<r<<"  "<<le<<' '<<ri<<"  "<<le1<<' '<<ri1<<endl;
		if(le1<ri1){//左边可以的比右边的少 
			if(c[le]!=c[ri]) ans+=le1;
			l+=le1;//左指针右移，右指针左移 
			r-=le1;
			ri1-=le1;
			le++;//下一种c[i]
			le1=a[le];
		}
		else if(le1==ri1){
			if(c[le]!=c[ri]) ans+=le1;
			l+=le1;
			r-=le1;
			le++;
			ri--;
			le1=a[le];
			ri1=a[ri];
		}
		else{
			if(c[le]!=c[ri]) ans+=ri1;
			l+=ri1;
			r-=ri1;
			le1-=ri1;
			ri--;
			ri1=a[ri];
		}
	}
	cout<<ans;
	return 0;
}

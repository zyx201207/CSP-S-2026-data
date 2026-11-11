#include<bits/stdc++.h>
using namespace std;
int n,x,a[200010],ans;
char c,ch[1980000000];
int pd(int x){
	if(x%2==0){
		return x/2;
	}
	else return (x+1)/2;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    x=1;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=x;j<=x+a[i]-1;j++)
			ch[j]=c;
		x+=a[i];
	}
	x-=1;
	for(int i=1;i<=pd(x);i++)
		if(ch[i]!=ch[x-i+1])
			ans++;
	cout<<ans<<endl;		
	return 0;
}

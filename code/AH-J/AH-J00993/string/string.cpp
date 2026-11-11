#include<bits/stdc++.h>
using namespace std;
struct{
	long long a;
	char b;
}mc[200005];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
	long long n,cnt=0,g[200005],h[200005];
	cin>>n;
	int q=1;
	for(int i=1;i<=n;i++){
		cin>>mc[i].a>>mc[i].b;
		cnt+=mc[i].a;
	}
	for(int i=1;i<=n;i++){
		if(i>=2){
			if(mc[i].b!=mc[i-1].b){
				q=0;
				break;
			}
		}
	}
	if(q==1){
		cout<<"0";
	}
	int v;
	if(cnt%2==0){
		v=1;
		for(int i=1;i<=cnt/2;i++){
			g[i]=mc[i].b;
		}
		for(int i=n;i>cnt/2;i++){
			h[(n+1)-i]=mc[i].b;
		}
	}else{
		v=0;
		for(int i=1;i<(cnt+1)/2;i++){
			g[i]=mc[i].b;
		}
		for(int i=n;i>(cnt+1)/2;i++){
			h[(n+1)-i]=mc[i].b;
		}
	}
	long long sum=0,sum1=0;
	if(v=1){
		for(int i=1;i<=cnt/2;i++){
			if(h[i]!=g[i]){
				sum++;
			}
			if(g[i]!=h[i]){
				sum1++;
			}
		}
	}else if(v=0){
		for(int i=1;i<=cnt;i++){
			if(h[i]!=g[i]){
				sum++;
			}
			if(g[i]!=h[i]){
				sum1++;
			}
		}
	}
	if(sum>=sum1){
		cout<<sum1;
	}else{
		cout<<sum;
	}
    return 0;
}

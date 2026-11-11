#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t;
char q[100000];
void put(char x){
	if(t<100000){
		t++;
		q[t]=x;
	}
}
void push(){
	if(t!=0){
		t--;
	}
}
char gettop(){
	return q[t];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char x[100000],y[100000];
	long long n,k,cnt=0;
	char number;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>number;
		for(int j=1;j<=k;j++){
			put(number);
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		x[i]=q[t-cnt+i];
	}
	for(int i=1;i<=cnt;i++){
		y[i]=gettop();
		push();
	}
	int cnt2=0;
	for(int i=1;i<=cnt;i++){
		if(x[i]!=y[i]){
			cnt2++;
		}
	}
	if(cnt2%2==0){
		cout<<cnt2/2;
	}else{
		cout<<(cnt2+1)/2;
	}
	return 0;
}

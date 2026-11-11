#include<bits/stdc++.h>
using namespace std;
unsigned int n;
struct NOD{
	int a;char c;
}b[20002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	b[1].a=1;
	int s=0;
	for(unsigned int i=1;i<=n;i++){
		int a1;char c1;
		cin>>a1;
		cin>>c1;
		b[i+1].a=a1+b[i].a;
		b[i].c=c1;
		s=s+a1;
	}
	int k=1,t=1,t1=0,l=1,cnt=0;
	for(int i=1;i<=s/2;i++){
		if(l>(b[k+1].a-1)){
			k++;l=1;
		}
		if(t>(b[n+1-t1].a-b[n-t1].a)){
			t1++;
			t=1;
		}
		if(b[k].c!=b[n-t1].c){
			cnt++;
		}
		l++;
		t++;
	}
	cout<<cnt;
	return 0;
}

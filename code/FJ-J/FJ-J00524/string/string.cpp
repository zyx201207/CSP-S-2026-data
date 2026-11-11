#include<bits/stdc++.h>
using namespace std;

 long long n;
struct Node{
	 long long s;
	char c;	
}l[200005];
 long long num=0;
 long long cnt=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i].s>>l[i].c;
		num+=l[i].s;
	}
	for(int i=1;i<=n/2;i++){
		if(l[i].c!=l[n+1-i].c){
			l[n+1-i].s-=l[i].s;
			if(l[n+1-i].s<0){
				l[n+1-i-1].s-=abs(l[n+1-i].s);
			}if(l[n+1-i].s>0){
				l[n+1-i-1].s-=abs(l[n+1-i].s);
			}else cnt+=l[i].s;
		}
	}
	cout<<cnt;

	return 0;
}


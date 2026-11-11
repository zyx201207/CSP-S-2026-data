#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node{
	long long start,end;
	char numb;
}a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long ans=0;
	long long cnt=0;
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long op;
		char c;
		cin>>op>>c;
		
		a[i].start=cnt+1;
		cnt+=op;
		a[i].end=cnt;
		a[i].numb=c;
	}
	/*int l=1,r=n;
	while(l<r){
		int now=a[l].end-a[l].start;
		int com=a[r].end-a[r].start;
		if(now>=com){
			if(a[l].numb!=a[r].numb)ans+=com;
			r--;
		}else{
			if(a[l].numb!=a[r].numb)ans+=now;
			l++; 
		}
	}
	cout<<ans;*/
	bool y=true;
	for(int i=2;i<=n;i++){
		if(!a[i].numb==a[i-1].numb)y=false;
	}
	if(!y)cout<<0;
	else cout<<cnt/2;
	return 0;
} //Trick||Treat!
/*
2
2 a
3 a*/



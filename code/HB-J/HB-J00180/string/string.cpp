#include<bits/stdc++.h>
using namespace std;
#define int long long
struct wod{
	int cnt;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,sum=0,id=1;
	cin>>n;
	int n1=n;
	for(int i=1;i<=n;i++,id++){
		cin>>a[id].cnt>>a[id].c;
		if(a[id].c==a[id-1].c) {a[id-1].cnt+=a[id].cnt;a[id].cnt=0;a[id].c=' ';n1--;id--;}
	}
	int l=1,r=n1;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].cnt<a[r].cnt) a[r].cnt-=a[l++].cnt;
			else a[l].cnt-=a[r--].cnt;
		}
		else{
			if(a[l].cnt<a[r].cnt) {sum+=a[l].cnt;a[r].cnt-=a[l++].cnt;}
			else {sum+=a[r].cnt;a[l].cnt-=a[r--].cnt;}
		}
	}		
	cout<<sum;	
	return 0;
}

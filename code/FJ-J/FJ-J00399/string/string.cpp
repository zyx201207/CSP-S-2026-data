#include<bits/stdc++.h>
using namespace std;
struct p{
	long long x;
	char c;
}a[200005];
long long ans,l,id;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	id=n;
	for(int i=1;i<=id;i++){
		l=a[i].x;
		while(l){
			if(a[id].x>l){
				a[id].x-=l;
				if(a[i].c!=a[id].c){
					ans+=l;
				}
				l=0;
			}else if(a[id].x==l){
				a[id].x-=l;
				if(a[i].c!=a[id].c){
					ans+=l;
				}
				id--;
				l=0;
			}else{
				l-=a[id].x;
				if(a[id].c!=a[i].c){
					ans+=a[id].x;
				}
				a[id].x=0;
				id--;
			}	
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

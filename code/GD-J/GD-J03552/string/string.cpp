#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long len=0,ans=0;
struct node{
	int num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		cin>>a[i].c;
		len+=a[i].num;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].num>a[r].num){
			if(a[l].c!=a[r].c){
				ans+=a[r].num;
			}
			a[l].num-=a[r].num; 
			a[r].num=0;
		}
		else{
			if(a[l].c!=a[r].c){
				ans+=a[l].num;
			}
			a[r].num-=a[l].num;
			a[l].num=0;
		}
		if(a[l].num==0)	l++;
		if(a[r].num==0)	r--;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
3
2 a
2 b
1 c
2

2
2 a
3 a
0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
3000000000
*/

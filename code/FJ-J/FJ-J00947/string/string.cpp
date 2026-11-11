/*
6
3 a
4 b
2 a
6 g
3 f
3 b
9

5
1 a
1 c
1 d
1 g
1 e
2

3
3 a
2 b
3 a
0 

5
1 a
3 s
2 a
4 f
2 s
5

7
100 a
100 b
99 c
100 d
100 c
100 b
100 a
1
*/
#include<bits/stdc++.h> 
using namespace std;
struct zf{
	long long d;
	char c;
}a[200010];
long long n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].c;
	}
	long long ans=0;
	long long l=1,r=n;
	while(l<r){
		if(a[l].d>a[r].d){
			if(a[l].c!=a[r].c){
				ans+=a[r].d;
			}
				a[l].d-=a[r].d;
				r--;
//			cout<<1<<endl;
		}else if(a[l].d<a[r].d){
			if(a[l].c!=a[r].c){
				ans+=a[l].d;
			}
				a[r].d-=a[l].d;
				l++;
//			cout<<2<<endl;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[l].d;
			}
				l++;
				r--;
//			cout<<3<<endl;
		}
//		cout<<1<<endl;
//		cout<<ans<<endl;
//cout<<l<<" "<<r<<endl;
	}
	cout<<ans;
	return 0;
}

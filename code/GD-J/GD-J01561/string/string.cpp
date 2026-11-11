#include<bits/stdc++.h>
using namespace std;
const int N=2e5+8;
struct node{
	long long a;
	char c;
}a[N];
long long n,len=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		len+=a[i].a;
	}
	long long l=1,r=len,indl=1,indr=n;
	while(l<=r&&indl<=indr&&indl<=n&&indr>=1){
		if(a[indl].c==a[indr].c){
			if(a[indl].a==a[indr].a){
				l+=a[indl].a;
				r-=a[indl].a;
				indl++;
				indr--;
			}
			else if(a[indl].a>a[indr].a){
				l+=a[indr].a;
				r-=a[indr].a;
				a[indl].a-=a[indr].a;
				indr--;
			}
			else{
				l+=a[indl].a;
				r-=a[indl].a;
				a[indr].a-=a[indl].a;
				indl++;
			}
		}
		else if(a[indl].a>a[indr].a){
			ans+=a[indr].a;
			l+=a[indr].a;
			r-=a[indr].a;
			a[indl].a-=a[indr].a;
			indr--;
		}
		else{
			ans+=a[indl].a;
			l+=a[indl].a;
			r-=a[indl].a;
			a[indr].a-=a[indl].a;
			indl++;
		}
	}
	cout<<ans;
	return 0;
}

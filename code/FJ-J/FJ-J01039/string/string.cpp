#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,r,ls,rs;
char c[200005];
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	ls=a[l];
	r=n;
	rs=a[r];
	while(l<r){
		if(c[r]==c[l]){
			if(ls>rs){
				r--;
				ls-=rs;
				rs=a[r];
			}
			else if(ls==rs){
				r--;
				l++;
				ls=a[l];
				rs=a[r];
			}
			else{
				l++;
				rs-=ls;
				ls=a[l];
			}
		}
		else{
			if(ls>rs){
				r--;
				ls-=rs;
				s+=rs;
				rs=a[r];
			}
			else if(ls==rs){
				r--;
				l++;
				s+=rs;
				ls=a[l];
				rs=a[r];
			}
			else{
				l++;
				s+=ls;
				rs-=ls;
				ls=a[l];
			}
		}
	}
	cout<<s;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

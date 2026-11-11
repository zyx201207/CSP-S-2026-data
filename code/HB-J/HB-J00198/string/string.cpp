#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	char ls=c[1],rs=c[n];
	long long li=a[1],ri=a[n];
	while(l<r){
		if(ls!=rs){
			if(li<ri){
				ri-=li;
				cnt+=li;
				l++;
				li=a[l];ls=c[l];
			}else if(li>ri){
				li-=ri;
				cnt+=ri;
				r--;
				ri=a[r];rs=c[r];
			}else{
				l++;r--;
				cnt+=li;
				li=a[l];ls=c[l];
				ri=a[r];rs=c[r];
			}
		}else{
			if(li<ri){
				ri-=li;
				l++;
				li=a[l];ls=c[l];
			}else if(li>ri){
				li-=ri;
				r--;
				ri=a[r];rs=c[r];
			}else{
				l++;r--;
				li=a[l];ls=c[l];
				ri=a[r];rs=c[r];
			}
		}
	}
	cout<<cnt;
	return 0;
}

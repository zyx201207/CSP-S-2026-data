#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
long long n,a[N],len;
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		flag+=a[i]%10%2;	
	}
	long long l=1,r=n,cl=a[1],cr=a[n],ans=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(cl<cr){
				l++;
				ans+=cl;
				cr-=cl;
				cl=a[l];
			}else if(cl==cr){
				ans+=cl;
				l++;
				r--;
				cl=a[l];
				cr=a[r];
			}else{
				ans+=cr;
				r--;
				cl-=cr;
				cr=a[r];
			}
		}else{
			if(cl<cr){
				l++;
				cr-=cl;
				cl=a[l];
			}else if(cl==cr){
				l++;
				r--;
				cl=a[l];
				cr=a[r];
			}else{
				r--;
				cl-=cr;
				cr=a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a;char in[maxn];
long long cnt,nu[maxn],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>nu[i]>>in[i];
	}cnt=nu[a];
	int l=1,r=a,cr=0,cl=0;
	bool gl=true,gr=true;ans=0;
	while(l<r){
		if(gl==true){
			cl=nu[l];
			gl=false;
		}
		if(gr==true){
			cr=nu[r];
			gr=false;
		}
		if(in[l]==in[r]){
			if(cl>cr){
				cl-=cr;
				r--;
				gr=true;
			}
			else if(cl<cr){
				cr-=cl;
				l++;gl=true;
			}
			else{
				r--;l++;gl=true;gr=true;
			}
		}
		else{
			if(cl>cr){
				cl-=cr;
				ans+=cr;
				r--;
				gr=true;
			}
			else if(cl<cr){
				cr-=cl;ans+=cl;
				l++;gl=true;
			}
			else{
				ans+=cr;
				r--;l++;gl=true;gr=true;
			}
		}
	}
	cout<<ans;
	return 0;
} 

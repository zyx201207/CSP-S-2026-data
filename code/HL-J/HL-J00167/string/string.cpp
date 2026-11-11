#include<bits/stdc++.h>
using namespace std;
struct s{
	long m;
	char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,l,r,t=0;
	long long ans=0;
	cin>>n;
	s a[200001]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		t+=a[i].m;
	}
	l=1;
	r=n;
	while(true){
		if(l==r){
			break;
		}
        if(a[l].m>a[r].m){
			if(a[l].c!=a[r].c){
				ans+=a[r].m;
				a[l].m-=a[r].m;
				r--;
			}
			else{
				a[l].m-=a[r].m;
				r--;
			}
		}
		else{
			if(a[l].c!=a[r].c){
				ans+=a[l].m;
				a[r].m-=a[l].m;
				l++;
			}
			else{
				a[r].m-=a[l].m;
				l++;
			}
		}
	}
	cout<<ans;
}

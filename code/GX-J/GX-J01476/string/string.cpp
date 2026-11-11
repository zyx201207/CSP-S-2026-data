#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int aa[n+5];
    bool bb[n+5];
    int ans=0,q=0;
    for(int i=0;i<n;i++){
		cin>>aa[i]>>bb[i];
	}
	int x=0,y=0;
	for(int i=0;i<n-1;i++){
		if(bb[i]-bb[i+1]!=0){
			x++;
		}
		if(aa[i]-aa[i+1]!=0){
			y++;
		}
	}
	if(x==0){
		cout<<"0";
	}
	if(x!=0&&y==0&&n%2==0){
		cout<<n*aa[0]/2;
		}
	if(x!=0&&y==0&&n%2!=0){
		cout<<(n-1)*aa[0]/2;
	}
	int maxx=aa[0];
	if(n==2&&x!=0&&y!=0){
		if(maxx<aa[1]){
			cout<<maxx;
		}
		if(maxx>aa[1]){
			cout<<aa[1];
		}
	}
}

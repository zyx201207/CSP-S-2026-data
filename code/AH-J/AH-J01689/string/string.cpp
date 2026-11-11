#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char ch[N];
int a[N],n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	int ans=0;
	int l=1,r=n;
	while(l<r){
       if(a[l]>a[r]){
       		if(ch[l]!=ch[r]) ans+=a[r];
       		a[l]-=a[r];
       		r--;
	   }else{
	   		if(ch[l]!=ch[r]) ans+=a[l];
       		a[r]-=a[l];
       		l++;
	   }
	}
	cout<<ans;
	return 0;
}

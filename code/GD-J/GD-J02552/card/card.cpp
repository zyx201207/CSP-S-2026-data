#include<bits/stdc++.h>
using namespace std;
int n,m,cnt1,cnt2;
int a[5e5+5],b[5e5+5],c[5e5+5];queue<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[n]==2||a[1]==2&&a[2]==1)cnt1++,cnt2++;
			if(a[i]==1&&a[n]==1)cout<<cnt1++;
			if(a[i]==2&&a[n]==2)cout<<cnt2++;	
		}
	} 
	cout<<cnt1<<" "<<cnt2;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],b[500010],d=1,e,c[500010],f,g,h,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	e=n;
	while(e>0){
		for(int i=d;i<=n;i++){
		    if(b[a[i]]!=0){
                for(int j=1;j<=i;j++)b[a[j]]=0;
		    }
		    b[a[i]]++;
	    }
	    for(int i=1;i<=m;i++){
	    	if(b[i]>0){
	    		c[i]++;
	    		b[i]=0;
			}
		}
		e--;
		d++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}

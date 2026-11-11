#include<bits/stdc++.h>
using namespace std;
long long mc,n,a[50000010],cut=0,aut=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>mc>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
	    if(cut>mc){
	    	cout<<aut;
	    	return 0;
		}
		cut+=(a[i]-a[i-1]);
		aut++;
        i++;    
		
    }
    cout<<aut;
	return 0;
}

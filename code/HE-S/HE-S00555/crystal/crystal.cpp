#include<bits/stdc++.h>
using namespace std;
long long m,n,a[50000010],cut=0,ant=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
	    if(cut>m){
	    	cout<<ant;
	    	return 0;
		}
		cut+=(a[i]-a[i-1]);
		ant++;
        i++;    
		
    }
    cout<<ant;
	return 0;
}

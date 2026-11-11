#include <iostream>
using namespace std;
int a[1000005]
int main(){
	freopen("and.in" ,"r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=0;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		if(i=1){
			if(m and a[i]>-1){
				c==m and a[i];
			}
		}else{
		    if(m and a[i]>m and a[i-1]){
		    	c==m and a[i];
			}
	    }
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
}


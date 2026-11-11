#include<bits/stdc++.h>
using namespace std; 
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	int x=0,l=1,r=n;
	while(l>=r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				x+=a[r];
				r--;
			}
			else if(a[r]>a[l]){
				a[r]=a[r]-a[l];
				x+=a[l];
				l++;
			}
			else{
				x+=a[l];
				l++;
				r--;
			}
		}
		else{
			l++;
			r--;
		}
	}
	cout<<x;
    
return 0;
}

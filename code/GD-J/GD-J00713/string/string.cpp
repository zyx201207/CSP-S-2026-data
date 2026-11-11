#include<bits/stdc++.h>
using namespace std;
int a[1000000];
char c[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    long long changdu=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	changdu+=a[i];
	}
	long long l=1,r=changdu,i=1,j=n;
	while(l<=r&&i<=j){
		if(a[i]>=a[j]){
			if(c[i]==c[j]){
				l+=a[j];
				r-=a[j];
			}
			else{
				l+=a[j];
				r-=a[j];
				cnt+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
        else{
			if(c[i]==c[j]){
				l+=a[i];
				r-=a[i];
			}
			else{
				l+=a[i];
				r-=a[i];
				cnt+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
	}
	cout<<cnt;
	return 0;
} 

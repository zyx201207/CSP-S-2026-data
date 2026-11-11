#include<bits/stdc++.h>
using namespace std;
long long n,sum;
char s[200005];
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++){
        	cin>>a[i]>>s[i];
		}
		
		int j=n;
		int i=1;
		while(i<j){
        	if(s[i]!=s[j]){
        		sum+=min(a[i],a[j]);
				if(a[i]==a[j]){
					a[i]=0;
					a[j]=0;
					i++;
					j--;
				} 
				else if(a[i]>a[j]) {
					a[i]-=a[j];
					a[j]=0;
					j--;
				}
				else {
					a[j]-=a[i];
					a[i]=0;
					i++;
				}
			}
    	else{
        	
				if(a[i]==a[j]){
					a[i]=0;
					a[j]=0;
					i++;
					j--;
				} 
				else if(a[i]>a[j]) {
					a[i]-=a[j];
					a[j]=0;
					j--;
				}
				else {
					a[j]-=a[i];
					a[i]=0;
					i++;
				}
			}
	}
	cout<<sum;
	return 0;
} 

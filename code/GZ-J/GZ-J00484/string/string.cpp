#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
char s[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int i=0,j=n-1,c=0;
	while(j>=i){
		if(c>0){
			a[i]=c;
			c=0;
		}else if(c<0){
			a[j]=0-c;
			c=0;
		}
		if(i==j){
			break;
		}
		if(s[i]==s[j]){
			c=a[i]-a[j];
			if(a[i]>a[j]){
				j--;
			}
			else if(a[i]<a[j]){
				i++;
			}else{
				i++;
				j--;
			} 
		}else{
			c=a[i]-a[j];
			if(a[i]>a[j]){
				sum+=a[j];
				j--;
			}
			else if(a[i]<a[j]){
				sum+=a[i];
				i++;
			}else{
				sum+=a[j];
				i++;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}

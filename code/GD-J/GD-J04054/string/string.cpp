#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[2*N+5];
string s[2*N+5];
long long size_n; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
		size_n+=a[i];
		if(s[i]==s[i-1]){
			a[i-1]+=a[i];
			n--;
			i--;
			continue;
		}
	}
	int i=1,j=n;
	while(i<j){
		if(s[i]==s[j]){
			size_n-=(2*min(a[i],a[j]));
			a[i]-=(2*min(a[i],a[j]));
			a[j]-=(2*min(a[i],a[j]));
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}else{
			if(a[i]<a[j]){
				i++;
				a[j]-=a[i];
			}else if(a[j]<a[i]){
				j--;
				a[i]-=a[j];
			}else{
				i++;
				j--;
			}
		}
	}
	if(i==j && a[i]!=0){
		size_n-=a[i];
	}
	long long ans=size_n/2;
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

long long s[200005],ans;
int a,n;
string aa,z[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>aa;
		s[i]=a;
		z[i]=aa;
	}
	int i=0,j=n-1;
	while(i<=j){
		if(z[i]==z[j]){
			if(s[i]>s[j]){
				s[i]=s[i]-s[j];
				j--;
			}else if(s[i]<s[j]){
				s[j]=s[j]-s[i];
				i++;
			}else{
				i++;
				j--;
			}
		}else{
			if(s[i]>s[j]){
				s[i]=s[i]-s[j];
				ans+=s[j];
				j--;
			}else if(s[i]<s[j]){
				s[j]=s[j]-s[i];
				ans+=s[i];
				i++;
			}else{
				ans+=s[i];
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
char s[200005];
long long c[200005],ans,j,i=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>s[i];
	}
	j=n;
	while(i<j){
		if(s[i]!=s[j]){
			if(c[i]>c[j]){
				ans+=c[j];
				c[i]-=c[j];
				c[j]=0;
				j--;
				continue;
			}
			else if(c[i]==c[j]){
				ans+=c[i];
				c[i]=0;
				c[j]=0;
				i++;
				j--;
				continue;
			}
			else{
				ans+=c[i];
				c[j]-=c[i];
				c[i]=0;
				i++;
				continue;
			}
		}
		else if(s[i]==s[j]){
			if(c[i]>c[j]){
				c[i]-=c[j];
				c[j]=0;
				j--;
				continue;
			}
			else if(c[i]==c[j]){
				i++;
				j--;
				c[i]=0;
				c[j]=0;
				continue;
			}
			else{
				c[i]=0;
				c[j]-=c[i];
				i++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}

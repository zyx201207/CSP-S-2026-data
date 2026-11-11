#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		s+=c;
	}
	s=' '+s;
	int i=1,j=n;
	while(i<=j){
		if(a[i]==a[j]){
			if(s[i]!=s[j]){
				ans+=a[i];
			}
		}
		else if(a[i]>a[j]&&a[j]!=0){
			if(s[i]==s[j]){
				int b=a[i]-a[j],c=1;
				a[j]+=b;
				ans+=b;
				while(b){
					if(b>a[j-c]){
						b-=a[j-c];
						a[j-c]=0;
					}
					else{
						a[j-c]-=b;
						b=0;
						break;
					}
					c++;
				}
			
			}else{
				int b=a[i],c=1;
				a[j]+=a[i];
				ans+=b;
				while(b){
					if(b>a[j-c]){
						b-=a[j-c];
						a[j-c]=0;
					}else{
						a[j-c]-=b;
						break;
					}
					c++;
				}
			}
		}
		else if(a[i]<a[j]&&a[i]!=0){
			if(s[i]==s[j]){
				int b=a[j]-a[i],c=1;
				a[j]+=b;
				ans+=b;
				while(b){
					if(b>a[i+c]){
						b-=a[i+c];
						a[i+c]=0;
					}
					else {
						a[i+1]-=b;
						break;
					}
					c++;
				}
			
			}else{
				int b=a[j],c=1;
				a[j]+=a[j];
				ans+=b;
				while(b){
					if(b>a[i+c]){
						b-=a[i+c];
						a[i+c]=0;
					}else{
						a[i+c]-=b;
					}
					c++;
				}
			}
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
} 

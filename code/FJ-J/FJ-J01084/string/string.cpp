#include<bits/stdc++.h> 
using namespace std;
long long n,a1,a[2*100010],m,ans,c,f=1,j,b[2*100010];
string s1,s[2*100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cin>>a1>>s1;
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		b[i]=a[i];
		m+=a[i];
	}
	for(int i=1;i<=n/2;){
		if(s[i]!=s[n+1-f]){
			if(a[i]>a[n+1-f]){
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				ans+=a[n+1-f];
				a[i]-=a[n+1-f];
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				f++;
			}
			else if(a[i]==a[n+1-f]){
				ans+=a[n+1-f];
				i++;
				f++;
			}
			else{
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				ans+=a[i];
				a[n+1-f]-=a[i];
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				i++;
			}
			//cout<<ans<<" ";
		}
		else{
			if(a[i]>a[n+1-f]){
				a[i]-=a[n+1-f];
				f++;
			}
			else{
				a[n+1-f]-=a[i];
				i++;
			}
		}
	}
	f=n;
	for(int i=n;i>=n/2;){
		if(s[i]!=s[n+1-f]){
			if(b[i]>b[n+1-f]){
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				c+=b[n+1-f];
				b[i]-=b[n+1-f];
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				f--;
			}
			else if(b[i]==b[n+1-f]){
				c+=a[n+1-f];
				i--;
				f--;
			}
			else{
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				c+=b[i];
				b[n+1-f]-=b[i];
				//cout<<a[i]<<" "<<a[n+1-f]<<endl; 
				i--;
			}
			//cout<<ans<<" ";
		}
		else{
			if(b[i]>b[n+1-f]){
				b[i]-=b[n+1-f];
				f--;
			}
			else{
				b[n+1-f]-=b[i];
				i--;
			}
		}
	}
	cout<<min(ans,c);
	return 0;
}


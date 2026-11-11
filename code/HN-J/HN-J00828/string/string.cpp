#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];
string s;
long long ans,sum;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}else if(n<=2000){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		long long len=s.size()/2;
		for(int i=0;i<=len;i++){
			if(s[i]==s[n-i+1]){
				continue;
			}else{
				ans++;
			}
		}
		cout<<ans;
		return 0; 
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			sum+=a[i];
		}
		int pos1=1,pos2=n;
	//	Å¼Êý
		if(n%2==0){
			for(int i=1;i<=n/2;i++){
				if(c[pos1]!=c[pos2]){
					if(a[pos1]>a[pos2]){
						ans+=a[pos2];
						a[pos1]-=a[pos2];
						pos2--;
					}else if(a[pos1]<a[pos2]){
						ans+=a[pos1];
						a[pos2]-=a[pos1];
						pos1++;
					}else{
						ans+=a[pos1];
						pos1++;
						pos2--;
					}
					if(pos1>=pos2){
						break;
					}
				}
			}
		}else{	//	ÆæÊý 
			for(int i=1;i<=(n+1)/2;i++){
				if(c[pos1]!=c[pos2]){
					if(a[pos1]>a[pos2]){
						ans+=a[pos2];
						a[pos1]-=a[pos2];
						pos2--;
					}else if(a[pos1]<a[pos2]){
						ans+=a[pos1];
						a[pos2]-=a[pos1];
						pos1++;
					}else{
						ans+=a[pos1];
						pos1++;
						pos2--;
					}
					if(pos1>pos2){
						break;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}


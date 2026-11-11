//GZ-J00591 六盘水市第二十四中学 王胤杰 
#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
long long s[200010];
char f[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long j=0;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		if(f[j-1]==c){
			s[j-1]+=a;
			continue;
		}
		s[j]=a;
		f[j]=c;
		j++;
	}
	if(j==1){
		cout<<0;
		return 0;
	}else if(j==2){
		cout<<min(s[0],s[1]);
		return 0;
	}
	for(long long i=1;i<=j/2;i++){
		long long k=j-i+1;
		if(f[i]!=f[k]){
			if(s[i]!=s[k]){
				if(s[i]>s[k]){
					f[k]=f[i];
					cnt+=s[k];
				}else{
					f[i]=f[k];
					cnt+=s[i];
				}
			}else{
				f[k]=f[i];
				cnt+=s[k];
			}
			continue;	
		}
		if(s[i]!=s[k]){
			if(s[i]>s[k]){
				s[i]=s[k];
				s[i+1]=s[i]-s[k];
				cnt+=s[i]-s[k];
			}else{
				s[k]=s[i];
				s[k-1]=s[k]-s[i];
				cnt+=s[k]-s[i];
			}
		}
	}
	cout<<cnt;
	return 0;
}

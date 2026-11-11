//GZ-J00096 黔西市第二中学 熊宇晨
#include<bits/stdc++.h>
using namespace std;
long long ans=0,num=1,him=0;
long long n;
long long a;
char c;
string s;
string m;//left
string x;//right
int main(){
	freopen("string.in","r","stdcin");
	freopen("string.out","w","stdcout");
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		ans+=a;
		for(long long j=num;j<=ans;j++){
			s[j]=c;
		}
		num+=a;
	}
	if(ans%2==0){
		for(long long i=1;i<=ans/2;i++){
			m[i]=s[i];	
		}
		for(long long i=1;i<=ans/2;i++){
			x[i]=s[ans/2+i];
		}
		for(long long i=1;i<=ans/2;i++){
			if(m[i]!=x[i]){
				him++;
			}
		}
	}else{
		for(long long i=1;i<=ans/2;i++){
			m[i]=s[i];	
		}
		for(long long i=1;i<=ans/2;i++){
			x[i]=s[ans/2+i+1];
		}
		for(long long i=1;i<=ans/2;i++){
			if(m[i]!=x[i]){
				him++;
			}
		}
	}
	cout<<him;
	return 0;
} 

#include <iostream>
using namespace std;
struct word{
	long long cnt;
	char c;
}a[200010];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	long long n;
	cin>>n;
	long long ans=0; 
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		ans+=a[i].cnt;
		for(int j=1;j<=a[i].cnt;j++){
			s=s+a[i].c;
		}
	}
	if(ans%2==1){
		long long h=ans/2+1;
		long long cnt=0;
		for(int i=1;i<=ans/2;i++){
			if(s[h+i-1]!=s[h-i-1]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	else{
		long long cnt=0;
		for(int i=0;i<ans/2;i++){
			if(s[ans/2-i]!=s[ans/2+1+i]) cnt++;
		}
		cout<<cnt;
	}
	
	return 0;
}

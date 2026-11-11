#include<iostream>
using namespace std;
int n,a[200010];
long long ans,len;
char c[200010];
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			x+=c[i];
		}
		len+=a[i];
	}
	if(len%2==1){//奇回文串 
		for(int i=1,j=len;i<=len/2,j>=(len/2)+2;i++,j--){
			if(x[i-1]!=x[j-1]){
				ans++;
			}
		}
	}else{//偶回文串 
		for(int i=1,j=len;i<=len/2,j>=(len/2)+1;i++,j--){
			if(x[i-1]!=x[j-1]){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

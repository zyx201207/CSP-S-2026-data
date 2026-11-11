//GZ-J00660 兴义市弘毅中学 陈润泽 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,x[N];
long long sum,r,l,ans;
string k;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	x[0]=1;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){	
 		scanf("%d",&x[i]);
		scanf("%s",&s[i]);	
		ans+=x[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){	
		for(int j=x[i-1];j<=x[i];j++){
			k[j]=s[i];
			
		}
	}
	int pan=0;
	for(int i=1;i<=ans;i++){
		if(k[i]==k[i+1]){
			pan++;
		}
		if(pan==ans){
			cout<<"0";
			return 0;
		}
	}
	l=1;r=ans;
	sum=0;
	while(r>l){
		if((k[l]-'0')!=(k[r]-'0')){
			sum++;
		}
		r--;l++;
	}
	printf("%lld",sum);
	return 0;
}

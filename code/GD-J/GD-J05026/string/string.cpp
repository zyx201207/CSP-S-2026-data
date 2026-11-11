#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
	long long ai;
	char c;
}a[200007];
string num;
long long len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].c;
		for(int j=1;j<=a[i].ai;j++){
			num+=a[i].c;
		}
		len+=a[i].ai;
	}
//	for(int i=0;i<len;i++){
//		cout<<num[i]<<" ";
//	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(len%2==0){
		string q,k;
		for(int i=0;i<(int)(num.size())/2;i++){
			q+=num[i];
		}
		//cout<<q<<'\n';
		for(int i=(int)(num.size())/2;i<(int)(num.size());i++){
			k+=num[i];
		}
		//cout<<k;
		long long ans=0;
		for(int i=(len/2)-1,j=0;i>=0&&j<(len/2);i--,j++){
			if(q[i]!=k[j]){
				ans++;
			}
		}
		cout<<ans;
	}
	if(len%2==1){
		string q,k;
		for(int i=0;i<(int)(num.size())/2;i++){
			q+=num[i];
		}
		//cout<<q<<'\n';
		for(int i=(int)(num.size())/2+1;i<(int)(num.size());i++){
			k+=num[i];
		}
		//cout<<k<<'\n';
		long long ans=0;
		for(int i=(len/2)-1,j=0;i>=0&&j<(len/2);i--,j++){
			if(q[i]!=k[j]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 

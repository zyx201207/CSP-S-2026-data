#include<bits/stdc++.h>
using namespace std;
long long n,a,sum,k,ans;
char c,b[200010],m[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		sum+=a;
		
		while(a>0){
			for(int i=1;i<=n;i++){
				b[i]+=c;
				a--;
			}
		}
			
		}
	
	if(n==1)
	{
		cout<<0;
	}
		if(n!=0){
			cout<<sum/2;
		}		
		
			int f=0;
	for(int i=1;i<=sum;i++){
		
		if(sum%2==1)
		{
		for(int k=1;k<=sum/2;k++)
		if(b[sum/2-k]==b[sum/2+k])
		{
			f++;	
		}
		
	}
	else if(sum%2==0)
	{
		for(int k=0;k<=sum/2;k++)
		if(b[sum/2-k]==b[sum/2+k+1]){
			f++;
		}
	}
		ans=sum/2-f;
	}
	if(f==0){
		cout<<sum/2;
		return 0;
	}
	
	return 0;
}

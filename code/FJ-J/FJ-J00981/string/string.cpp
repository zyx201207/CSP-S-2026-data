#include<bite/stdc++.h>
using namespace std;
int n,a,b,S[1000000005],c,ans;
int main()
{
	freopen('string.in','r',stdin);
	freopen('string.out','w',stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		c+=a;
		for(int j=0;j<a;j++)
		{
			S[i+j]=b;
		}
	}if(c%2==0){
		for(int i=0;i<c/2;i++){
			if(a[i]!=a[i+c]){
				ans+=1;
			}
		}
	}else{
		for(int i=0;i<(c-1)/2){
			if(i+c/2<c){
				if(a[i]!=a[i+c])
					ans+=1;
			}
		}
	}cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
//long long !!!!!!!!!
long long n,a[200005],t[200005],sum=0,sum1=0,ans=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		t[i]=c;
		sum+=a[i];
	}
	int flag=0;
	if((sum&1)) flag=1;
	sum/=2;
	int ef;
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		if(sum1>sum){
			long long c1,c2;
			a[i]-=flag;
			sum1-=flag;
			c2=sum1-sum;
			c1=sum-sum1+a[i];
			if(c1>=c2){
				a[i]=c1-c2;
				ef=i+1;
			}
			else{
				a[i]=c2-c1;
				ef=i;
			}
			break;
		}
		if(sum1==sum){
			a[i+1]-=flag;
			ef=i+1;
			break;
		}
	}
	//cout<<a[3]<<" test\n";
	int top=ef-1;
	for(int i=ef;i<=n;i++){
		while(top>=1&&a[i]>=a[top]){
			if(t[i]!=t[top]){
				ans+=a[top];
			}
			a[i]-=a[top];
			top--;
		}
		if(t[i]!=t[top]){
			ans+=a[i];
		}
		a[top]-=a[i];
	}
	cout<<ans;
} 

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n;
long long a[N];
char c[N];
long long sum,cnt;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=n;i>0;i--){
		int op=n-i+1;
		//if(op==i)continue'\;
			while(1){
				if(c[op]!=c[i]){
					c[op]=c[i];
				sum+=min(a[i],a[op]);
				if(a[i]>=a[op])a[i]-=a[op],a[op]=0,op++;
				else a[op]-=a[i],a[i]=0,i--;
				
				}
				if(a[i]>=[op]){
					a[i]-=a[op],a[op]=0,op++;
					if(a[i]==0)break;
				}
				else{
					if(a[op]==0)break;
					a[op]-=a[i],a[i]=0,i--;
				}
			} 
	}
	cout<<sum;
	return 0;
}

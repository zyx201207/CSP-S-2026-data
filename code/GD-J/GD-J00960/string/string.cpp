#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,sum,jj,anss;
char s[200005];
char ij;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	long long summ=sum;
	sum/=2;
	if(summ!=sum*2){
		sum++;
	}
	summ=sum;
	for(int i=1;i<=n;i++){
		sum-=a[i];
		if(sum<=0){
			ij=s[i];
			jj=i;
			break;
		}
	}
	sum=summ;
	summ=0;
	for(int i=1;i<=jj;i++){
		summ+=a[i];
		long long ans=a[i];
		if(summ>sum){
			ans=summ-sum;
		}
		int j=n-i+1;
		while(ans!=0){
			if(i==j){
				break; 
			}
			if(s[j]==s[i]&&i!=j){
				ans-=a[j];
				a[j]=0;
				if(ans<0){
					a[j]-=ans;
					ans-=ans;
				}else{
					j--;
				}
			}else{
				anss+=a[j];
				ans-=a[j];
				a[j]=0;
				if(ans<0){
					anss+=ans;
					a[j]-=ans;
					ans-=ans;
				}else{
					j--;
				}
			}
		}
	}
	cout<<anss;
	return 0;
}

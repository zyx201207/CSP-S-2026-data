#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum,ans;
char c[200005];
void pr1(){
	return ;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum/=2;
	int l=1,r=n;
	while(1){
		if(a[l]>a[r]){
			if(sum<=a[r]){
				a[l]-=sum;
				if(c[l]!=c[r]) ans+=sum;
				sum=0;
				pr1();
				break;
			}
			else{
				sum-=a[r];
				if(c[l]!=c[r]) ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else if(a[l]<a[r]){
			if(sum<=a[l]){
				a[r]-=sum;
				if(c[l]!=c[r]) ans+=sum;
				sum=0;
				pr1();
				break;
			}
			else{
				sum-=a[l];
				if(c[l]!=c[r]) ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			
		}
		else{
			if(sum<=a[l]){
				a[r]-=sum;
				if(c[l]!=c[r]) ans+=sum;
				sum=0;
				pr1();
				break;
			}
			else{
				sum-=a[l];
				if(c[l]!=c[r]) ans+=a[l];
				a[l]=a[r]=0;
				l++,r--;
			}
		}
		pr1();
	}
	cout<<ans;
	return 0;
}//24474


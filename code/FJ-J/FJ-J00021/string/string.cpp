#include<bits/stdc++.h>
using namespace std;
struct node{
unsigned long long x;
char y;
}a[211000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	unsigned long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		l+=a[i].x;
	}
	unsigned long long k=0,q=0;
	for(int i=1;i<=n;i++){
		k+=a[i].x;
		if(k>=(l+1)/2){
			q=i;
			break;
		}
	
	}
	//cout<<q<<" "<<k<<endl;
	//cout<<l<<endl;
	unsigned long long ans=0;
	int i=1,j=n;
	for(;;)
	{
		if(i>=j)break;
		if(a[i].y==a[j].y){
			if(a[i].x>a[j].x){
			    a[i].x-=a[j].x;
			    j--;
			}
			else if(a[i].x==a[j].x)
			{
				i++;
				j--;
			}
			else {
				a[j].x-=a[i].x;
				i++;
			}
		}
		else{
			if(a[i].x>a[j].x){
			    a[i].x-=a[j].x;
			    ans+=a[j].x;
			    j--;
			}
			else if(a[i].x==a[j].x)
			{
				ans+=a[i].x;
				i++;
				j--;
			}
			else {
				a[j].x-=a[i].x;
				ans+=a[i].x;
				i++;
			}
		}
		//cout<<i<<" "<<j<<endl;
	}

	/*if(j==q){
		if(a[i].y!=a[q].y)ans+=a[i].x;
	}
	else {
		if(a[j].y!=a[q].y)ans+=a[j].x;
	}*/
	cout<<ans<<endl;
	return 0;
}

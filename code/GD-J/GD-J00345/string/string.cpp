#include<iostream>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}long long sum=0;
	int i=1,j=n;
	while(i<j){
		if(a[i]<a[j]){
			if(c[i]!=c[j]){
				sum+=a[i];	
			}a[j]-=a[i];
			i++;
		}else if(a[i]==a[j]){
			if(c[i]!=c[j]){
				sum+=a[i];	
			}a[j]=0;
			a[i]=0;
			i++;
			j--;
		}else{
			if(c[i]!=c[j]){
				sum+=a[j];	
			}a[i]-=a[j];
			j--;
		}
	}
	cout<<sum;
	return 0;
}
	

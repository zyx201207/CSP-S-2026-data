#include<iostream>
#include<string>
using namespace std;
int a[200006];
string s[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}//i---n-i+1;
	int i=1,j=n;
	while(a[i]>0&&a[j]>0){
		if(s[i]!=s[j]){
			if(a[i]<=a[j]){
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
			}else{
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
			}
		}else{
			if(a[i]<=a[j]){
				a[j]-=a[i];
				a[i]=0;
			}else{
				a[i]-=a[j];
				a[j]=0;
			}
		}
		if(a[i]<=0){
			i++;
		}
		if(a[j]<=0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}

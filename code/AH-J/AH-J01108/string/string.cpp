#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200005];
    char b[200005];
    for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int kk=1,ll=n;
	int sum=n;
	long long ans=0;
	while(sum>1){
		if(b[kk]==b[ll]){
			if(a[kk]>a[ll]){
				a[kk]-=a[ll];
				ll--;
				sum--;
			}
			else if(a[kk]<a[ll]){
				a[ll]-=a[kk];
				kk++;
				sum--;
			}
			else{
				sum-=2;
				ll--;
				kk++;
			}
	    }
	    else{
			if(a[kk]>a[ll]){
				a[kk]-=a[ll];
				ans+=a[ll];
				ll--;
				sum--;
			}
			else if(a[kk]<a[ll]){
				a[ll]-=a[kk];
				ans+=a[kk];
				kk++;
				sum--;
			}
			else{
				sum-=2;
				ans+=a[kk];
				ll--;
				kk++;
			}
		}
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
